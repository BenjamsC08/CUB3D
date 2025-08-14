#include "cub3d.h"

int	encode_trgb(t_byte t, t_byte r, t_byte g, t_byte b)
{
	return (*(int *)(t_byte[4]){b, g, r, t});
}

t_byte	get_t(int trgb)
{
	return (((t_byte *)&trgb)[3]);
}

t_byte	get_r(int trgb)
{
	return (((t_byte *)&trgb)[2]);
}

t_byte	get_g(int trgb)
{
	return (((t_byte *)&trgb)[1]);
}

t_byte	get_b(int trgb)
{
	return (((t_byte *)&trgb)[0]);
}
