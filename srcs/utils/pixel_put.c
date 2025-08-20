#include "cub3d.h"

<<<<<<< HEAD
void	ft_pixel_put(t_data_img data_img, char **addr, int pos[2], int color)
=======
void	ft_clear_background(t_game *game, int color)
{
	void	*img;
	char	*addr;
	int		pos[2];

	img = mlx_new_image(game->mlx, W_WIDTH, W_HEIGHT);
	addr = mlx_get_data_addr(img, &game->data_img.bpp, &game->data_img.ll, &game->data_img.endian);
	pos[0] = -1;
	while (++pos[0] < W_HEIGHT)
	{
		pos[1] = -1;
		while (++pos[1] < W_WIDTH)
			ft_pixel_put(game->data_img, &addr, pos, color);
	}
	mlx_put_image_to_window(game->mlx, game->win, img, 0, 0);
	mlx_destroy_image(game->mlx, img);
}

void	ft_pixel_put(t_data_img data_img, char **addr, int pos[], int color)
>>>>>>> f1f8776 (not finished draw rectangle)
{
	char	*dst;

	dst = *addr + (pos[0] * data_img.ll + pos[1] * (data_img.bpp / 8));
	*(unsigned int*)dst = color;
}
