#include "cub3d.h"

int	key_pressed(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_all(game);
	else if (keycode == W_KEY)
		game->player->key_up = TRUE;
	else if (keycode == A_KEY)
		game->player->key_left = TRUE;
	else if (keycode == S_KEY)
		game->player->key_down = TRUE;
	else if (keycode == D_KEY)
		game->player->key_right = TRUE;
	else if (keycode == M_KEY)
		game->minimap->disp_map = TRUE;
	else if (keycode == CAPS && game->minimap->disp_map == TRUE)
		game->minimap->disp_map = FALSE;
	else if (keycode == CAPS && game->minimap->disp_map == FALSE)
		game->minimap->disp_map = TRUE;
	else if (keycode == SPACE)
		set_start_time(game);
	else
		ft_printf("key unknown press code :%d\n", keycode);
	return (0);
}

int	key_released(int keycode, t_game *game)
{
	if (keycode == W_KEY)
		game->player->key_up = FALSE;
	if (keycode == A_KEY)
		game->player->key_left = FALSE;
	if (keycode == S_KEY)
		game->player->key_down = FALSE;
	if (keycode == D_KEY)
		game->player->key_right = FALSE;
	if (keycode == M_KEY)
		game->minimap->disp_map = FALSE;
	return (0);
}

int	looping_hook(t_game *game)
{
	ft_clear_background(game, MLX_BLACK);
	if (game->minimap->disp_map == TRUE)
		draw_map(game);
	else
		draw_minimap(game);
	mlx_put_image_to_window(game->mlx, game->win, game->data_img->img, 0, 0);
	return (0);
}

int game_loop(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, key_pressed, game);
	mlx_hook(game->win, 3, 1L << 1, key_released, game);
	mlx_hook(game->win, 17, 1L << 0, close_all, game);
	mlx_loop_hook(game->mlx, looping_hook, game);
	mlx_loop(game->mlx);
	return (0);
}


int main(int argc, char **argv)
{
	t_game	game;

	(void)argc;
	(void)argv;
	if (argc != 2)
		return (not_a_good_file(0), 1);
	if (!init_base(&game))
		return (1);
	if (!good_file_ext(argv[1]))
		return (close_all(&game), 1);
	if (!load_cub_file(&game, argv[1]))
		return (close_all(&game));
	if (!create_num(&game))
		return (close_all(&game));
	if (!start_time(&game))
		return (close_all(&game));
	game_loop(&game);
	return (0);
}
