#include "cub3d.h"

#include <stdio.h>

void	draw_wall(t_game *game)
{
	char  **map;
	t_rect r;
	const int w = ((game->minimap->map.w) / game->data_desc->line_length);
	const int h = ((game->minimap->map.h) / game->data_desc->nb_line);
	int diffw = (game->minimap->map.w) - (game->data_desc->line_length * w);
	int diffh = (game->minimap->map.h) - (game->data_desc->nb_line * h);
	game->minimap->map.h -= diffh;
	game->minimap->map.w -= diffw;
	map = game->data_desc->map;
	for (int y = 0; map[y]; y++)
	{
		for (int x = 0; map[y][x]; x++)
		{
			if (map[y][x] == '1')
			{
				r.x = (x * w) + game->minimap->map.x;
				r.y = (y * h) + game->minimap->map.y;
				r.w = w;
				r.h = h;
				draw_rect(game, r, MLX_RED);
			}
			if (map[y][x] == '2')
			{
				r.x = (x * w) + game->minimap->map.x;
				r.y = (y * h) + game->minimap->map.y;
				r.w = w;
				r.h = h;
				draw_rect(game, r, MLX_GREEN);
			}
			if (map[y][x] == '3')
			{
				r.x = (x * w) + game->minimap->map.x;
				r.y = (y * h) + game->minimap->map.y;
				r.w = w;
				r.h = h;
				draw_rect(game, r, MLX_YELLOW);
			}
			if (ft_ischarset(map[y][x], "NSWE"))
			{
				r.x = (x * w) + game->minimap->map.x;
				r.y = (y * h) + game->minimap->map.y;
				r.w = w;
				r.h = h;
				draw_rect(game, r, MLX_PURPLE);
			}
		}

	}
}

void	draw_map(t_game *game)
{
	draw_wall(game);
	draw_rect(game, game->minimap->map, MLX_GREY);
}
