#include "cub3d.h"

int	looping_hook(t_game *game)
{
	move(game);
	rotate(game);
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
	if (!init_player(&game))
		return (close_all(&game), 0);
	/*game.minimap->disp_map = TRUE;*/
	game_loop(&game);
	return (0);
}
