#include "cub3d.h"

int	encode_rgb(t_byte r, t_byte g, t_byte b)
{
	return (*(int *)(t_byte[4]){b, g, r, 0});
}

t_byte	get_r(int rgb)
{
	return (((t_byte *)&rgb)[2]);
}

t_byte	get_g(int rgb)
{
	return (((t_byte *)&rgb)[1]);
}

t_byte	get_b(int rgb)
{
	return (((t_byte *)&rgb)[0]);
}
