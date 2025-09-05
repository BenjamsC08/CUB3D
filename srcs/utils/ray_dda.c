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
