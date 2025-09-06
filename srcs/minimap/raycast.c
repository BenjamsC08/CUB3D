/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 23:31:42 by mkerrien          #+#    #+#             */
/*   Updated: 2025/09/06 07:00:32 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief  Test whether a world position is blocked.
 *
 * Converts a floating-point world coordinate (ray_x, ray_y) into
 * grid indices using BLOCK and checks map bounds and collision tiles.
 * Returns 1 if outside the map or on a blocking tile ('1' or '2'),
 * otherwise 0.
 *
 * @param  game    Global game context providing map and dimensions.
 * @param  ray_x   World X coordinate in pixels (float).
 * @param  ray_y   World Y coordinate in pixels (float).
 * @return 1 if blocked (collision or outside the map), 0 if free.
 *
 * @note   Integer cast floors toward zero when mapping to grid cells.
 * @warning No sub-tile collision; purely cell-based blocking.
 * @pre    data_desc fields (map, nb_line, line_length) are consistent.
 * @post   None.
 */
static int	is_blocked(t_game *game, float ray_x, float ray_y)
{
	int	grid_x;
	int	grid_y;

	grid_x = (int)(ray_x / (float)BLOCK);
	grid_y = (int)(ray_y / (float)BLOCK);
	if (grid_x < 0 || grid_y < 0
		|| grid_y >= game->data_desc->nb_line
		|| grid_x >= game->data_desc->line_length)
		return (TRUE);
	if (game->data_desc->map[grid_y][grid_x] == '1'
		|| game->data_desc->map[grid_y][grid_x] == '2')
		return (TRUE);
	return (FALSE);
}

/**
 * @brief  Cast and draw a single ray until collision.
 *
 * Starts from the player's position and advances by a unit step vector
 * (cos(angle), sin(angle)) each iteration, plotting pixels along the path
 * until a blocking cell is reached or a safety counter expires.
 *
 * @param  game   Global game context (player, map, pixel plotting).
 * @param  angle  Ray angle in radians.
 * @return None.
 *
 * @note   The safety counter (maximum ray length) is the diagonal of
 *		   the window in order to avoid infinite loops.
 * @warning Fixed step length of 1 px may undersample; diagonal bias possible.
 * @pre    Player position and angle are valid; ft_pixel_put is available.
 * @post   Pixels of a certain color are drawn along the ray up to
 *		   the first collision.
 */
static void	cast_ray(t_game *game, float angle)
{
	float	ray_x;
	float	ray_y;
	float	step_x;
	float	step_y;
	int		safety_counter;

	ray_x = game->player->x;
	ray_y = game->player->y;
	step_x = cosf(angle);
	step_y = sinf(angle);
	safety_counter = (int)sqrtf(W_WIDTH * W_WIDTH + W_HEIGHT * W_HEIGHT);
	while (safety_counter > 0 && !is_blocked(game, ray_x, ray_y))
	{
		ft_pixel_put(game, (int)ray_x, (int)ray_y, MLX_GREEN);
		ray_x += step_x;
		ray_y += step_y;
		safety_counter--;
	}
}

/**
 * @brief  Render a fan of rays across the player's FOV and mark the player.
 *
 * Casts n_rays rays uniformly over the horizontal field of view centered
 * on the player's facing angle. Each ray is drawn via cast_ray(). Finally,
 * draws a filled rectangle at the player's position to visualize them on
 * the minimap.
 *
 * @param  game  Global game context (player state, FOV, draw utilities).
 * @return None.
 *
 * @note   Uses FOV_DEG (in degrees) and converts to radians via DEGREE.
 * @warning Ray count (n_rays=1200) impacts performance linearly.
 * @pre    Player coordinates and angle are up-to-date; colors defined.
 * @post   Rays and the player marker are visible on the minimap.
 */
void	draw_rays(t_game *game)
{
	const int	n_rays = 1200;
	const float	start_angle = game->player->angle
		- (FOV_DEG * DEGREE) * 0.5f;
	const float	angle_step = (FOV_DEG * DEGREE) / (float)n_rays;
	t_rect		player_rect;
	int			i;

	i = -1;
	while (++i < n_rays)
		cast_ray(game, start_angle + angle_step * (float)i);
	player_rect.x = game->player->x - (BLOCK / 2);
	player_rect.y = game->player->y - (BLOCK / 2);
	player_rect.w = BLOCK;
	player_rect.h = BLOCK;
	draw_frect(game, player_rect, MLX_PURPLE);
}
