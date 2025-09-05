/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 01:38:54 by mkerrien          #+#    #+#             */
/*   Updated: 2025/09/05 03:10:32 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <stdio.h> // DEBUG

void	draw_minimap(t_game *game)
{
	const char  **minimap = (const char **)game->data_desc->map;
	t_rect		r;
	int			i;
	int			j;

	/*game->minimap->minimap.h -= game->data_desc->nb_line * BLOCK;*/
	/*game->minimap->minimap.w -= game->data_desc->line_length * BLOCK;*/
	r.w = BLOCK;
	r.h = BLOCK;
	
	i = -1;
	while (minimap[++i])
	{
		j = -1;
		while (minimap[i][++j])
		{
			r.x = (j * BLOCK) + game->minimap->minimap.x;
			r.y = (i * BLOCK) + game->minimap->minimap.y;
			if (minimap[i][j] == '1')
				draw_frect(game, r, MLX_RED);
			if (minimap[i][j] == '2')
				draw_rect(game, r, MLX_GREEN);
			if (minimap[i][j] == '3')
				draw_rect(game, r, MLX_YELLOW);
			if (ft_ischarset(minimap[i][j], "NSWE"))
			{
				draw_rays(game, game->player->x, game->player->y);
				draw_frect(game, r, MLX_PURPLE);
			}
		}
	}
	draw_rect(game, game->minimap->minimap, MLX_GREY);
}

void	init_minimap(t_game *game)
{
	game->minimap->minimap.x = 0;
	game->minimap->minimap.y = 0;
	game->minimap->minimap.w = W_WIDTH;
	game->minimap->minimap.h = W_HEIGHT;
}
