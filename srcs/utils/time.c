#include "cub3d.h"


t_uint	get_current_time(void)
{
	struct timeval	current_time;
	t_uint			out;

	gettimeofday(&current_time, NULL);
	out = current_time.tv_sec;
	return (out);
}

int set_start_time(t_game *game)
{
	pthread_mutex_lock(game->timer->mtx_time);
	if (!game->timer->start_time)
		game->timer->start_time = get_current_time();
	return (pthread_mutex_unlock(game->timer->mtx_time), 1);

}
