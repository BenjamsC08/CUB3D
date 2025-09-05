/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 23:31:42 by mkerrien          #+#    #+#             */
/*   Updated: 2025/09/05 15:10:16 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_blocked(t_game *game, float ray_x, float ray_y)
{
	int	grid_x;
	int	grid_y;

	grid_x = (int)(ray_x / (float)BLOCK);
	grid_y = (int)(ray_y / (float)BLOCK);
	if (grid_x < 0 || grid_y < 0
		|| grid_y >= game->data_desc->nb_line
		|| grid_x >= game->data_desc->line_length)
		return (1);
	if (game->data_desc->map[grid_y][grid_x] == '1'
		|| game->data_desc->map[grid_y][grid_x] == '2')
		return (1);
	return (0);
}

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
	safety_counter = W_WIDTH + W_HEIGHT;
	while (safety_counter > 0 && !is_blocked(game, ray_x, ray_y))
	{
		ft_pixel_put(game, (int)ray_x, (int)ray_y, MLX_GREEN);
		ray_x += step_x;
		ray_y += step_y;
		safety_counter--;
	}
}

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
