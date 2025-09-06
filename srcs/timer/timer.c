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
			usleep(10);
			continue ;
		}
		game->timer->time = get_current_time() - game->timer->start_time;
		if (game->timer->time >= game->timer->max_time)
			return (pthread_mutex_unlock(game->timer->mtx_time), NULL);
		ft_printf("time: %d:%d\r", game->timer->max_time/60 -game->timer->time/60, game->timer->max_time%60 - game->timer->time %60);
		pthread_mutex_unlock(game->timer->mtx_time);
	}
	pthread_mutex_destroy(game->timer->mtx_run);
	pthread_mutex_destroy(game->timer->mtx_time);
}

int	start_time(t_game *game)
{
	game->timer = ft_gcalloc(game->gc_head, sizeof(t_timer));
	if (!game->timer)
		return (0);
	game->timer->mtx_time = ft_gcalloc(game->gc_head, sizeof(t_mtx));
	if (!game->timer->mtx_time)
		return (0);
	game->timer->mtx_run = ft_gcalloc(game->gc_head, sizeof(t_mtx));
	if (!game->timer->mtx_run)
		return (0);
	game->timer->run = TRUE;
	game->timer->start_time = 0;
	game->timer->max_time = 130;
	if (pthread_mutex_init(game->timer->mtx_time, NULL) != 0)
		return (0);
	if (pthread_mutex_init(game->timer->mtx_run, NULL) != 0)
		return (pthread_mutex_destroy(game->timer->mtx_time), 0);
	if (pthread_create(&game->timer->thread, NULL, time_job, (void *)game) != 0)
		return (pthread_mutex_destroy(game->timer->mtx_run), pthread_mutex_destroy(game->timer->mtx_time), 0);
	pthread_detach(game->timer->thread);
	return (1);
}

void	draw_point(t_game *game, t_uint size, t_rect frame, int color)
{
	t_uint k;
	t_uint l;

	k = -1;
	while (++k < size * 5)
	{
		l = -1;
		while (++l < size * 3)
		{
			ft_pixel_put(game, frame.x+l, frame.y+k, color);
		}
	}

}

void	put_map(t_game *game, t_uint size, int color, t_rect frame, t_uint time)
{
	int **tab = game->tab_num[time];
	t_uint i;
	t_uint h;

	i = -1;
	while (++i < 5)
	{
		h = -1;
		while (++h < 3)
		{
			ft_printf("%d\n", tab[i][h]);
			if (tab[i][h] == 1)
			{
				frame.x += size * h;
				frame.y += size * i;
				draw_point(game, size, frame, color);
				frame.x -= size * h;
				frame.y -= size * i;
			}
		}
	}
}

void	put_timer(t_game *game, t_uint size, int color, t_rect frame)
{
	/*t_uint time;*/
	/*t_uint min;*/
	/*t_uint sec;*/
	
	/*pthread_mutex_lock(game->timer->mtx_time);*/
	/*if (!game->timer->start_time)*/
	/*	time = game->timer->max_time;*/
	/*else*/
	/*	time = game->timer->max_time - game->timer->time;*/
	/*pthread_mutex_unlock(game->timer->mtx_time);*/
	/*min = time / 60;*/
	/*sec = time % 60;*/
	put_map(game, size, color, get_rect(frame.x, frame.y, frame.w/3, frame.h/5), 2);
	// put_map(game, size, color, get_rect(frame.x + (1 + frame.w/3), frame.y, frame.w/3, frame.h/5), min%60);
	// put_map(game, size, color, get_rect(frame.x + (2 + frame.w/3), frame.y, frame.w/3, frame.h/5), 10);
	// put_map(game, size, color, get_rect(frame.x + (3 + frame.w/3), frame.y, frame.w/3, frame.h/5), sec/60);
	// put_map(game, size, color, get_rect(frame.x + (4 + frame.w/3), frame.y, frame.w/3, frame.h/5), sec%60);
}
