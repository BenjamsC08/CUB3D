#include "cub3d.h"

void	ft_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->data_img.addr + (y * game->data_img.ll + x * (game->data_img.bpp / 8));
	*(unsigned int*)dst = color;
}

void	ft_clear_background(t_game *game, int color)
{
	void	*img;
	int		y;
	int		x;

	img = mlx_new_image(game->mlx, W_WIDTH, W_HEIGHT);
	game->data_img.addr = mlx_get_data_addr(img, &game->data_img.bpp, &game->data_img.ll, &game->data_img.endian);
	y = -1;
	while (++y < W_HEIGHT)
	{
		x = -1;
		while (++x < W_WIDTH)
			ft_pixel_put(game, x, y, color);
	}
	mlx_put_image_to_window(game->mlx, game->win, img, 0, 0);
	mlx_destroy_image(game->mlx, img);
}
