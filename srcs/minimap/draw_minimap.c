/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 01:38:54 by mkerrien          #+#    #+#             */
/*   Updated: 2025/09/05 15:17:47 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_minimap_row(t_game *game, const char **map, int row)
{
	t_rect	cell;
	int		col;

	cell.w = BLOCK;
	cell.h = BLOCK;
	col = 0;
	while (map[row][col])
	{
		cell.x = col * BLOCK;
		cell.y = row * BLOCK;
		if (map[row][col] == '1')
			draw_frect(game, cell, MLX_GREY);
		if (map[row][col] == '2')
			draw_frect(game, cell, MLX_BORDEAUX);
		if (map[row][col] == '3')
			draw_rect(game, cell, MLX_BORDEAUX);
		if (ft_ischarset(map[row][col], "NSWE"))
			draw_rect(game, cell, MLX_PURPLE);
		col++;
	}
}

void	draw_minimap(t_game *game)
{
	const char	**map = (const char **)game->data_desc->map;
	int			row;

	row = -1;
	while (map[++row])
		draw_minimap_row(game, map, row);
	draw_rect(game, game->minimap->minimap, MLX_YELLOW);
}

void	init_minimap(t_game *game)
{
	game->minimap->minimap.x = 0;
	game->minimap->minimap.y = 0;
	game->minimap->minimap.w = W_WIDTH;
	game->minimap->minimap.h = W_HEIGHT;
}
