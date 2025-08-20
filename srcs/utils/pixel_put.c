#include "cub3d.h"

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
void	ft_pixel_put(t_data_img data_img, char **addr, int pos[2], int color)
=======
=======
void	ft_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->data_img.addr + (y * game->data_img.ll + x * (game->data_img.bpp / 8));
	*(unsigned int*)dst = color;
}

>>>>>>> c59306a (reset all)
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
<<<<<<< HEAD
}

void	ft_pixel_put(t_data_img data_img, char **addr, int pos[], int color)
>>>>>>> f1f8776 (not finished draw rectangle)
=======
void	ft_pixel_put(t_data_img data_img, char **addr, int pos[2], int color)
>>>>>>> 260c476 (????)
{
	char	*dst;

	dst = *addr + (pos[0] * data_img.ll + pos[1] * (data_img.bpp / 8));
	*(unsigned int*)dst = color;
=======
	game->data_img.addr = NULL;
>>>>>>> c59306a (reset all)
}
