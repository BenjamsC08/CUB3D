#include "cub3d.h"

t_rect	get_rect(int pos[2], int width, int height, int color)
{
	t_rect rect;

	rect.y = pos[0];
	rect.x = pos[1];
	rect.w = width;
	rect.h = height;
	rect.color = color;
	return (rect);
}
