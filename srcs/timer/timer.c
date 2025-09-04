# include "cub3d.h"

int		running(t_game *game)
{
	pthread_mutex_lock(game->timer->mtx_run);
	if (game->timer->run == FALSE)
		return (pthread_mutex_unlock(game->timer->mtx_run), FALSE);
	return (pthread_mutex_unlock(game->timer->mtx_run), TRUE);
}

void	*time_job(void *ptr_game)
{
	t_game *game;

	game = (t_game *)ptr_game;
	while (42)
	{
		if (!running(game))
			return (NULL);
		pthread_mutex_lock(game->timer->mtx_time);
		if (!game->timer->start_time)
		{
			pthread_mutex_unlock(game->timer->mtx_time);
			continue ;
		}
		game->timer->time = get_current_time() - game->timer->start_time;
		if (game->timer->time >= game->timer->max_time)
			return (pthread_mutex_unlock(game->timer->mtx_time), NULL);
		ft_printf("time: %d:%d\r", game->timer->time/60, game->timer->time %60);
		pthread_mutex_unlock(game->timer->mtx_time);
	}
}

int	start_time(t_game *game)
{
	t_timer *timer;

	timer = ft_gcalloc(game->gc_head, sizeof(t_timer));
	if (!timer)
		return (0);
	timer->run = TRUE;
	timer->start_time = 0;
	timer->max_time = 130;
	timer->mtx_time = ft_gcalloc(game->gc_head, sizeof(t_mtx));
	if (!timer->mtx_time)
		return (0);
	if (pthread_mutex_init(timer->mtx_time, NULL) != 0)
		return (pthread_mutex_destroy(timer->mtx_time), 0);
	timer->mtx_run = ft_gcalloc(game->gc_head, sizeof(t_mtx));
	if (!timer->mtx_run)
		return (pthread_mutex_destroy(timer->mtx_time), 0);
	if (pthread_mutex_init(timer->mtx_run, NULL) != 0)
		return (pthread_mutex_destroy(timer->mtx_time), 0);
	if (pthread_create(&timer->thread, NULL, time_job, (void *)game) != 0)
		return (pthread_mutex_destroy(timer->mtx_run), pthread_mutex_destroy(timer->mtx_time), 0);
	game->timer = timer;
	return (1);
}
