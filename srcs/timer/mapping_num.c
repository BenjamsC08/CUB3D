#include "cub3d.h"

static int	  get_nb1(t_game *game);
static int	  get_nb2(t_game *game);
static int	  get_nb3(t_game *game);
static int	  get_nb4(t_game *game);

int create_num(t_game *game)
{
	game->tab_num = ft_gcalloc(game->gc_head, sizeof(char **) * 11);
	if (!game->tab_num)
		return (0);
	if (!get_nb1(game))
		return (0);
	return (1);
}

//* transformer le char[][] en int [][] avec une func pour dupliquer les int */


int	**cint_tabdup(const int tab[][])
{
	printf("size tab", sizeof(tab));
}

static int	  get_nb1(t_game *game)
{
	const char	nb1[5][3] = {{'1', '1', '1'},{'1', '0', '1'},{'1', '0', '1'},{'1', '0', '1'},{'1', '1', '1'}};
	const char	nb2[5][3] = {{'0', '0', '1'},{'0', '0', '1'},{'0', '0', '0'},{'0', '0', '1'},{'0', '0', '1'}};
	const char	nb3[5][3] = {{'1', '1', '1'},{'0', '1', '1'},{'0', '1', '0'},{'1', '1', '0'},{'1', '1', '1'}};

	game->tab_num[0] = ft_add_strs_gc(game->gc_head, ft_strsdup((char **)nb1));
	if (!game->tab_num[0])
		return (0);
	game->tab_num[1] = ft_add_strs_gc(game->gc_head, ft_strsdup((char **)nb2));
	if (!game->tab_num[1])
		return (0);
	game->tab_num[2] = ft_add_strs_gc(game->gc_head, ft_strsdup((char **)nb3));
	if (!game->tab_num[2])
		return (0);
	if (!get_nb2(game))
		return (0);
	return (1);
}


static int	  get_nb2(t_game *game)
{
	const char	nb1[5][3] = {{'1', '1', '1'},{'0', '0', '1'},{'1', '1', '1'},{'1', '0', '0'},{'1', '1', '1'}};
	const char	nb2[5][3] = {{'1', '0', '1'},{'1', '0', '1'},{'1', '1', '1'},{'0', '0', '0'},{'0', '0', '1'}};
	const char	nb3[5][3] = {{'1', '1', '1'},{'1', '1', '0'},{'0', '1', '0'},{'0', '1', '1'},{'1', '1', '1'}};

	game->tab_num[3] = ft_add_strs_gc(game->gc_head, ft_strsdup((char **)nb1));
	if (!game->tab_num[3])
		return (0);
	game->tab_num[4] = ft_add_strs_gc(game->gc_head, ft_strsdup((char **)nb2));
	if (!game->tab_num[4])
		return (0);
	game->tab_num[5] = ft_add_strs_gc(game->gc_head, ft_strsdup((char **)nb3));
	if (!game->tab_num[5])
		return (0);
	if (!get_nb3(game))
		return (0);
	return (1);
}

static int	  get_nb3(t_game *game)
{
	const char	nb1[5][3] = {{'1', '1', '1'},{'1', '0', '0'},{'1', '1', '1'},{'1', '0', '1'},{'1', '1', '1'}};
	const char	nb2[5][3] = {{'1', '1', '1'},{'0', '0', '1'},{'0', '1', '1'},{'0', '0', '1'},{'0', '0', '1'}};
	const char	nb3[5][3] = {{'1', '1', '1'},{'1', '0', '1'},{'1', '1', '1'},{'1', '0', '1'},{'1', '1', '1'}};

	game->tab_num[6] = ft_add_strs_gc(game->gc_head, ft_strsdup((char **)nb1));
	if (!game->tab_num[6])
		return (0);
	game->tab_num[7] = ft_add_strs_gc(game->gc_head, ft_strsdup((char **)nb2));
	if (!game->tab_num[7])
		return (0);
	game->tab_num[8] = ft_add_strs_gc(game->gc_head, ft_strsdup((char **)nb3));
	if (!game->tab_num[8])
		return (0);
	if (!get_nb4(game))
		return (0);
	return (1);
}


static int	  get_nb4(t_game *game)
{
	const char	nb1[5][3] = {{'1', '1', '1'},{'1', '0', '1'},{'1', '1', '1'},{'0', '0', '1'},{'1', '1', '1'}};
	const char	nb2[5][3] = {{'0', '1', '1'},{'0', '1', '0'},{'0', '0', '0'},{'0', '1', '0'},{'0', '1', '0'}};

	game->tab_num[9] = ft_add_strs_gc(game->gc_head, ft_strsdup((char **)nb1));
	if (!game->tab_num[9])
		return (0);
	game->tab_num[10] = ft_add_strs_gc(game->gc_head, ft_strsdup((char **)nb2));
	if (!game->tab_num[10])
		return (0);
	return (1);
}
