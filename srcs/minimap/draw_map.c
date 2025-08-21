#include "cub3d.h"

void	draw_wall(t_game *game)
{
	char  **map;
	t_rect r;

	map = game->data_desc->map;
	for (int y = 0; map[y]; y++)
	{
		for (int x = 0; map[y][x]; x++)
		{
			if (map[y][x] == '1')
			{
				r.x = 1 + x * BLOCK;
				r.y = 1 + y * BLOCK;
				r.w = BLOCK;
				r.h = BLOCK;
				draw_rect(game, r, MLX_RED);
			}
		}

	}
}

void	draw_map(t_game *game)
{
	draw_rect(game, game->minimap->map, MLX_GREY);
	draw_wall(game);
}
