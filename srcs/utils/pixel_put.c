#include "cub3d.h"

void	ft_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x >= W_WIDTH || x < 0 || y >= W_HEIGHT || y < 0)
		return ;

	dst = game->data_img->addr + (y * game->data_img->ll + x * (game->data_img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	ft_clear_background(t_game *game, int color)
{
	int		y;
	int		x;

	game->data_img->addr = mlx_get_data_addr(game->data_img->img, &game->data_img->bpp, &game->data_img->ll, &game->data_img->endian);
	y = -1;
	while (++y < W_HEIGHT)
	{
		x = -1;
		while (++x < W_WIDTH)
			ft_pixel_put(game, x, y, color);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->data_img->img, 0, 0);
}
