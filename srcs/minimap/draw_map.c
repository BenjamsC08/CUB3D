#include "cub3d.h"

#include <stdio.h>

void	draw_wall(t_game *game)
{
	const char  **map = (const char **)game->data_desc->map;
	t_rect r;
	const int w = ((game->minimap->map.w) / game->data_desc->line_length);
	const int h = ((game->minimap->map.h) / game->data_desc->nb_line);
	int	pos[2];

	game->minimap->map.h -= (game->minimap->map.h) - (game->data_desc->nb_line * h);
	game->minimap->map.w -= (game->minimap->map.w) - (game->data_desc->line_length * w);
	r.w = w;
	r.h = h;
	pos[0] = -1;
	while (map[++pos[0]])
	{
		pos[1] = -1;
		while (map[pos[0]][++pos[1]])
		{
			r.x = (pos[1] * w) + game->minimap->map.x;
			r.y = (pos[0] * h) + game->minimap->map.y;
			if (map[pos[0]][pos[1]] == '1')
				draw_rect(game, r, MLX_RED);
			if (map[pos[0]][pos[1]] == '2')
				draw_rect(game, r, MLX_GREEN);
			if (map[pos[0]][pos[1]] == '3')
				draw_rect(game, r, MLX_YELLOW);
			if (ft_ischarset(map[pos[0]][pos[1]], "NSWE"))
				draw_rect(game, r, MLX_PURPLE);
		}
	}
}

void	draw_map(t_game *game)
{
	draw_wall(game);
	draw_rect(game, game->minimap->map, MLX_GREY);
}

void	draw_minimap(t_game *game)
{
	(void)game;
}

int init_minimap(t_game *game)
{
	game->minimap = ft_gcalloc(game->gc_head, sizeof(t_minimap));
	if (!game->minimap)
		return (0);
	game->minimap->map.x = W_WIDTH/2 - (W_WIDTH/4);
	game->minimap->map.y = W_HEIGHT/2  - (W_HEIGHT/4);
	game->minimap->map.w = (W_WIDTH/2);
	game->minimap->map.h = (W_HEIGHT/2);
	game->minimap->disp_map = FALSE;
	return (1);
}
