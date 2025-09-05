/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 23:31:42 by mkerrien          #+#    #+#             */
/*   Updated: 2025/09/05 03:11:18 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h> // DEBUG

void	grid_to_pixel(int x, int y, float *dst_x, float *dst_y, t_game *game)
{
	// prendre en compte l'offset
	// convertir 
	*dst_x = game->minimap->map.x + (x * BLOCK);
	*dst_y = game->minimap->map.y + (y * BLOCK);
}

void	pixel_to_grid(float x, float y, int *dst_x, int *dst_y, t_game *game)
{
	*dst_x = (x - game->minimap->map.x) / BLOCK;
	*dst_y = (y - game->minimap->map.y) / BLOCK;
}

static int collide(t_game *game, float pixel_x, float pixel_y)
{
	/*dprintf(2, "DEBUG : pixel_x = %f    pixel_y = %f\n", pixel_x, pixel_y);*/
	const int	x = pixel_x / BLOCK;
	const int	y = pixel_y / BLOCK;

	if (game->data_desc->map[y][x] == '1' || game->data_desc->map[y][x] == '2')
		return (TRUE);
	/*dprintf(2, "DEBUG : x = %d    y = %d\nIn map, this cell is a '%c'\n", x, y, game->data_desc->map[y][x]);*/
	/*dprintf(2, "DEBUG : line_length = %d    nb_line = %d\n", game->data_desc->line_length, game->data_desc->nb_line);*/
	return (FALSE);
}

void	draw_rays(t_game *game, float player_x, float player_y)
{
	float		ray_x;
	float		ray_y;
	const float	cos_angle = cos(game->player->angle);
	const float	sin_angle = sin(game->player->angle);

	ray_x = player_x;
	ray_y = player_y;
	/*dprintf(2, "DEBUG : ray_x = %f    ray_y = %f\n", ray_x, ray_y);*/
	while (!collide(game, ray_x, ray_y))
	{
		ft_pixel_put(game, ray_x, ray_y, MLX_GREEN);
		ray_x += cos_angle;
		ray_y += sin_angle;
	}
}
