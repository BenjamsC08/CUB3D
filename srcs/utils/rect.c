#include "cub3d.h"

t_rect	get_rect(int x, int y, int width, int height)
{
	t_rect rect;

	rect.y = y;
	rect.x = x;
	rect.w = width;
	rect.h = height;
	return (rect);
}

void	draw_rect(t_game *game, t_rect rect, int color)
{
	int x;
	int y;

	y = -1;
	while (++y < rect.h)
	{
		x = -1;
		while (++x < rect.w)
		{
			if ((y == 0 || x == 0) || ((y == rect.h - 1) || x == (rect.w - 1)))
				ft_pixel_put(game, rect.x + x, rect.y + y, color);
		}
	}
}

void	draw_frect(t_game *game, t_rect rect, int color)
{
	int x;
	int y;

	y = -1;
	while (++y < rect.h)
	{
		x = -1;
		while (++x < rect.w)
			ft_pixel_put(game, rect.x + x, rect.y + y, color);
	}
}
