#include "cub3d.h"

void  stop_thread(t_game *game)
{
	pthread_mutex_lock(game->timer->mtx_run);
	game->timer->run = FALSE;
	pthread_mutex_unlock(game->timer->mtx_run);
}

int  close_all(t_game *game)
{
	stop_thread(game);
	if (game->data_img->img)
		mlx_destroy_image(game->mlx, game->data_img->img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	ft_clear_gc(game->gc_head);
	exit (0);
}
