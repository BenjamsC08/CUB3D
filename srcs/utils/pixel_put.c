#include "cub3d.h"

void	ft_pixel_put(t_data_img data_img, char **addr, int pos[], int color)
{
	char	*dst;

	dst = *addr + (pos[0] * data_img.ll + pos[1] * (data_img.bpp / 8));
	*(unsigned int*)dst = color;
}
