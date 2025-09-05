/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 23:31:42 by mkerrien          #+#    #+#             */
/*   Updated: 2025/09/05 09:59:12 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h> // DEBUG

void	grid_to_pixel(int x, int y, float *dst_x, float *dst_y, t_game *game)
{
	*dst_x = game->minimap->minimap.x + (x * BLOCK);
	*dst_y = game->minimap->minimap.y + (y * BLOCK);
}

void	pixel_to_grid(float x, float y, int *dst_x, int *dst_y, t_game *game)
{
	*dst_x = (x - game->minimap->minimap.x) / BLOCK;
	*dst_y = (y - game->minimap->minimap.y) / BLOCK;
}

static int collide(t_game *game, float pixel_x, float pixel_y)
{
	const int	x = pixel_x / BLOCK;
	const int	y = pixel_y / BLOCK;

	if (x < 0 || y < 0 || y >= game->data_desc->nb_line || x >= game->data_desc->line_length)
		return (TRUE);
	return (game->data_desc->map[y][x] == '1' || game->data_desc->map[y][x] == '2');
}

static void	draw_ray(t_game *game, float ray_x, float ray_y)
{
	const float	cos_angle = cosf(game->player->angle);
	const float	sin_angle = sinf(game->player->angle);

	while (!collide(game, ray_x, ray_y))
	{
		ft_pixel_put(game, ray_x, ray_y, MLX_GREEN);
		ray_x += cos_angle;
		ray_y += sin_angle;
	}
}

void	draw_rays(t_game *game, float player_x, float player_y)
{
	float		i;
	float		ray_x;
	float		ray_y;

	ray_x = player_x - (BLOCK / 2);
	ray_y = player_y - (BLOCK / 2);
	i = 0;
	while (i < BLOCK)
	{
		draw_ray(game, ray_x + i, ray_y);
		i++;
	}
}
