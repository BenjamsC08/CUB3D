#include "cub3d.h"

int	init_base(t_game *game)
{
	game->gc = init_gc();
	if (!game->gc)
		return (0);
	game->gc_head = &(game->gc);
	game->mlx = ft_gc_addnode(game->gc_head, mlx_init());
	if (!game->mlx)
		return (ft_clear_gc(game->gc_head), 0);
	game->win = mlx_new_window(game->mlx, W_WIDTH, W_HEIGHT,
			"CUB3D");
	if (!game->win)
		return (ft_clear_gc(game->gc_head), 0);
	game->data_desc = ft_gcalloc(game->gc_head, sizeof(t_data_desc));
	if (!game->data_desc)
		return (ft_clear_gc(game->gc_head), 0);
	return (1);
}

int  close_all(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	ft_clear_gc(game->gc_head);
	return (1);
}

static int	key_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_all(game);
	return (0);
}

int game_loop(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, key_hook, game);
	mlx_hook(game->win, 17, 1L << 0, close_all, game);
	mlx_loop(game->mlx);
	return (0);
}


int main(int argc, char **argv)
{
	t_game	game;

	(void)argc;
	(void)argv;
	if (argc != 2)
		return (not_a_good_file(0));
	if (!init_base(&game))
		return (1);
	if (!good_file_ext(argv[1]))
		return (close_all(&game), not_a_good_file(EXT));
	if (!load_cub_file(&game, argv[1]))
		return (close_all(&game));
	// game_loop(&game);
	close_all(&game);
	return (0);
}
