#include "cub3d.h"

static int	  get_nb1(t_game *game);
static int	  get_nb2(t_game *game);
static int	  get_nb3(t_game *game);
static int	  get_nb4(t_game *game);

int create_num(t_game *game)
{
	game->tab_num = ft_gcalloc(game->gc_head, sizeof(int **) * 11);
	if (!game->tab_num)
		return (0);
	if (!get_nb1(game))
		return (0);
	return (1);
}

static int	  get_nb1(t_game *game)
{
	const int	nb1[5][3] = {{1, 1, 1},{1, 0, 1},{1, 0, 1},{1, 0, 1},{1, 1, 1}};
	const int	nb2[5][3] = {{0, 0, 1},{0, 0, 1},{0, 0, 0},{0, 0, 1},{0, 0, 1}};
	const int	nb3[5][3] = {{1, 1, 1},{0, 1, 1},{0, 1, 0},{1, 1, 0},{1, 1, 1}};

	game->tab_num[0] = ft_1d_to_2d_int(game->gc_head, &nb1[0][0], 5, 3);
	if (!game->tab_num[0])
		return (0);
	game->tab_num[1] = ft_1d_to_2d_int(game->gc_head, &nb2[0][0], 5, 3);
	if (!game->tab_num[1])
		return (0);
	game->tab_num[2] = ft_1d_to_2d_int(game->gc_head, &nb3[0][0], 5, 3);
	if (!game->tab_num[2])
		return (0);
	return (get_nb2(game));
}


static int	  get_nb2(t_game *game)
{
	const int	nb1[5][3] = {{1, 1, 1},{0, 0, 1},{1, 1, 1},{1, 0, 0},{1, 1, 1}};
	const int	nb2[5][3] = {{1, 0, 1},{1, 0, 1},{1, 1, 1},{0, 0, 0},{0, 0, 1}};
	const int	nb3[5][3] = {{1, 1, 1},{1, 1, 0},{0, 1, 0},{0, 1, 1},{1, 1, 1}};

	game->tab_num[3] = ft_1d_to_2d_int(game->gc_head, &nb1[0][0], 5, 3);
	if (!game->tab_num[3])
		return (0);
	game->tab_num[4] = ft_1d_to_2d_int(game->gc_head, &nb2[0][0], 5, 3);
	if (!game->tab_num[4])
		return (0);
	game->tab_num[5] = ft_1d_to_2d_int(game->gc_head, &nb3[0][0], 5, 3);
	if (!game->tab_num[5])
		return (0);
	return (get_nb3(game));
}

static int	  get_nb3(t_game *game)
{
	const int	nb1[5][3] = {{1, 1, 1},{1, 0, 0},{1, 1, 1},{1, 0, 1},{1, 1, 1}};
	const int	nb2[5][3] = {{1, 1, 1},{0, 0, 1},{0, 1, 1},{0, 0, 1},{0, 0, 1}};
	const int	nb3[5][3] = {{1, 1, 1},{1, 0, 1},{1, 1, 1},{1, 0, 1},{1, 1, 1}};

	game->tab_num[6] = ft_1d_to_2d_int(game->gc_head, &nb1[0][0], 5, 3);
	if (!game->tab_num[6])
		return (0);
	game->tab_num[7] = ft_1d_to_2d_int(game->gc_head, &nb2[0][0], 5, 3);
	if (!game->tab_num[7])
		return (0);
	game->tab_num[8] = ft_1d_to_2d_int(game->gc_head, &nb3[0][0], 5, 3);
	if (!game->tab_num[8])
		return (0);
	return (get_nb4(game));
}


static int	  get_nb4(t_game *game)
{
	const int	nb1[5][3] = {{1, 1, 1},{1, 0, 1},{1, 1, 1},{0, 0, 1},{1, 1, 1}};
	const int	nb2[5][3] = {{0, 1, 1},{0, 1, 0},{0, 0, 0},{0, 1, 0},{0, 1, 0}};

	game->tab_num[9] = ft_1d_to_2d_int(game->gc_head, &nb1[0][0], 5, 3);
	if (!game->tab_num[9])
		return (0);
	game->tab_num[10] = ft_1d_to_2d_int(game->gc_head, &nb2[0][0], 5, 3);
	if (!game->tab_num[10])
		return (0);
	return (1);
}
