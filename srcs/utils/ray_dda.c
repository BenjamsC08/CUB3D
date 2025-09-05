/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_dda.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:34:35 by mkerrien          #+#    #+#             */
/*   Updated: 2025/09/05 15:39:54 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief  Compute delta distances for a ray.
 *
 * Sets delta.x and delta.y for the DDA algorithm. These represent the
 * distance a ray must travel in grid units along the x or y axis before
 * crossing to the next grid line. Handles division by zero by assigning
 * FLT_MAX if a direction component is 0.
 *
 * @param  ray  Ray structure containing direction and delta fields.
 * @return None.
 *
 * @note   fabsf(1/dir) ensures positive step sizes for both directions.
 * @warning If ray->dir.x or ray->dir.y is zero, delta is set to FLT_MAX.
 * @pre    ray->dir must be initialized.
 * @post   ray->delta contains valid step lengths for DDA traversal.
 */
static void	ray_set_delta(t_ray *ray)
{
	if (ray->dir.x == 0.0f)
		ray->delta.x = FLT_MAX;
	else
		ray->delta.x = fabsf(1.0f / ray->dir.x);
	if (ray->dir.y == 0.0f)
		ray->delta.y = FLT_MAX;
	else
		ray->delta.y = fabsf(1.0f / ray->dir.y);
}

/**
 * @brief  Initialize ray stepping direction and side distances.
 *
 * Sets the step direction (+1 or -1) for both x and y axes and computes
 * the initial side distances from the ray origin to the first grid boundary.
 * These values are required by the DDA algorithm to know which axis to step
 * first and when to cross cell boundaries.
 *
 * @param  ray     Ray structure to initialize.
 * @param  pos_x   Player’s position in grid units (float).
 * @param  pos_y   Player’s position in grid units (float).
 * @return None.
 *
 * @note   Uses delta.x and delta.y previously computed in ray_set_delta().
 * @warning Caller must ensure pos_x/pos_y and ray->mapx/mapy are consistent.
 * @pre    ray->dir and ray->delta must be valid.
 * @post   ray->stepx/stepy and ray->side.{x,y} are initialized.
 */
static void	ray_set_step_and_side(t_ray *ray, float pos_x, float pos_y)
{
	if (ray->dir.x < 0.0f)
	{
		ray->stepx = -1;
		ray->side.x = (pos_x - ray->mapx) * ray->delta.x;
	}
	else
	{
		ray->stepx = 1;
		ray->side.x = (ray->mapx + 1.0f - pos_x) * ray->delta.x;
	}
	if (ray->dir.y < 0.0f)
	{
		ray->stepy = -1;
		ray->side.y = (pos_y - ray->mapy) * ray->delta.y;
	}
	else
	{
		ray->stepy = 1;
		ray->side.y = (ray->mapy + 1.0f - pos_y) * ray->delta.y;
	}
}

/**
 * @brief  Prepare a ray for a given screen column.
 *
 * Computes the ray direction from player position and camera plane, sets
 * initial map coordinates, and initializes delta/side distances for the DDA
 * algorithm. This is the per-column setup before running ray traversal.
 *
 * @param  game       Global game context with player and map data.
 * @param  ray        Ray structure to initialize.
 * @param  screen_x   Current screen column (0..W_WIDTH-1).
 * @return None.
 *
 * @note   camera_x ranges from -1 (left) to +1 (right) across the screen.
 * @warning Assumes BLOCK, W_WIDTH, and FOV constants are consistent.
 * @pre    game->player is initialized and valid.
 * @post   ray contains direction, starting grid cell, step, and side values.
 */
void	ray_setup(t_game *game, t_ray *ray, int screen_x)
{
	t_vec	dir_vec;
	t_vec	plane_vec;
	float	camera_x;
	float	pos_x;
	float	pos_y;

	compute_cam_vectors(game->player, &dir_vec, &plane_vec);
	pos_x = game->player->x / (float)BLOCK;
	pos_y = game->player->y / (float)BLOCK;
	camera_x = 2.0f * (float)screen_x / (float)W_WIDTH - 1.0f;
	ray->dir.x = dir_vec.x + plane_vec.x * camera_x;
	ray->dir.y = dir_vec.y + plane_vec.y * camera_x;
	ray->mapx = (int)pos_x;
	ray->mapy = (int)pos_y;
	ray_set_delta(ray);
	ray_set_step_and_side(ray, pos_x, pos_y);
}

/**
 * @brief  Perform the DDA loop to find a wall hit.
 *
 * Iteratively advances the ray in either x or y direction depending on the
 * smallest side distance, until it either hits a wall ('1' or '2') or leaves
 * the map bounds. Updates ray->mapx/mapy, side_hit, and tile accordingly.
 *
 * @param  game  Global game context with map data.
 * @param  ray   Ray structure containing initial setup values.
 * @return None.
 *
 * @note   ray->tile is set to 0 if the ray exits the map without a hit.
 * @warning Infinite loop is prevented by bounds checks; ensure map is closed
 *          for expected behavior.
 * @pre    ray_setup() must have been called before.
 * @post   ray->mapx, ray->mapy, side_hit, and tile are updated.
 */
void	ray_run_dda(t_game *game, t_ray *ray)
{
	while (1)
	{
		if (ray->side.x < ray->side.y)
		{
			ray->side.x += ray->delta.x;
			ray->mapx += ray->stepx;
			ray->side_hit = 0;
		}
		else
		{
			ray->side.y += ray->delta.y;
			ray->mapy += ray->stepy;
			ray->side_hit = 1;
		}
		if (ray->mapx < 0 || ray->mapy < 0
			|| ray->mapy >= game->data_desc->nb_line
			|| ray->mapx >= game->data_desc->line_length)
		{
			ray->tile = 0;
			return ;
		}
		ray->tile = game->data_desc->map[ray->mapy][ray->mapx];
		if (ray->tile == '1' || ray->tile == '2')
			return ;
	}
}

/**
 * @brief  Compute perpendicular distance from player to wall hit.
 *
 * Calculates the corrected distance to the wall using the final ray position,
 * step direction, and side of impact. This eliminates the fish-eye effect
 * by projecting the hit distance perpendicularly onto the camera plane.
 *
 * @param  game  Global game context with player position.
 * @param  ray   Ray structure containing hit information.
 * @return Perpendicular distance to the wall hit (float).
 *
 * @note   Uses player position in grid units (player.x/BLOCK, player.y/BLOCK).
 * @warning Division by ray->dir.x or ray->dir.y assumes non-zero components.
 * @pre    ray_run_dda() has set ray->mapx, mapy, side_hit, and stepx/stepy.
 * @post   Returns the corrected wall distance for perspective projection.
 */
float	ray_perp_dist(t_game *game, t_ray *ray)
{
	const float	play_grid_x = game->player->x / (float)BLOCK;
	const float	play_grid_y = game->player->y / (float)BLOCK;
	float		dist;

	if (ray->side_hit == 0)
		dist = (ray->mapx - play_grid_x + (1 - ray->stepx) * 0.5f) / ray->dir.x;
	else
		dist = (ray->mapy - play_grid_y + (1 - ray->stepy) * 0.5f) / ray->dir.y;
	return (dist);
}
