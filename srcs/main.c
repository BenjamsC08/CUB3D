#include "cub3d.h"

int	looping_hook(t_game *game)
{
	moves(game);
	ft_clear_background(game, MLX_BLACK);
	if (game->minimap->disp_map == TRUE)
	{
		draw_minimap(game);
		draw_rays(game);
	}
	else
		render_frame(game);
	/*put_timer(game, 5, MLX_GREY, get_rect(W_WIDTH/2, W_HEIGHT/2, 200, 200));*/
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
	// Revoir/modifier algo DDA ?
	t_game	game;

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
	if (!create_num(&game))
		return (close_all(&game));
	if (!start_time(&game))
		return (close_all(&game));
	game_loop(&game);
	return (0);
}
