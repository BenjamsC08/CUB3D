#include "cub3d.h"

int  close_all(t_game *game)
{
	if (game->data_img->img)
		mlx_destroy_image(game->mlx, game->data_img->img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	ft_clear_gc(game->gc_head);
	exit (0);
}
