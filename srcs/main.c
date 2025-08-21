#include "cub3d.h"

void init_minimap(t_game *game)
{
	game->minimap = ft_gcalloc(game->gc_head, sizeof(t_minimap));
	if (!game->minimap)
		return ((void)ft_clear_gc(game->gc_head));
	game->minimap->map.x = W_WIDTH/2 - (W_WIDTH/4);
	game->minimap->map.y = W_HEIGHT/2  - (W_HEIGHT/4);
	game->minimap->map.w = (W_WIDTH/2);
	game->minimap->map.h = (W_HEIGHT/2);
}

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
	game->data_desc->player = FALSE;
	game->data_img = ft_gcalloc(game->gc_head, sizeof(t_data_img));
	if (!game->data_img)
		return (ft_clear_gc(game->gc_head), 0);
	game->data_img->img = mlx_new_image(game->mlx, W_WIDTH, W_HEIGHT);
	game->data_img->addr = mlx_get_data_addr(game->data_img->img, &game->data_img->bpp, &game->data_img->ll,&game->data_img->endian);
	mlx_put_image_to_window(game->mlx, game->win, game->data_img->img, 0, 0);
	game->player = ft_gcalloc(game->gc_head, sizeof(t_player));
	if (!game->player)
		return (ft_clear_gc(game->gc_head), 0);
	init_minimap(game);
	return (1);
}

int  close_all(t_game *game)
{
	if (game->data_img->img)
		mlx_destroy_image(game->mlx, game->data_img->img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	ft_clear_gc(game->gc_head);
	exit (0);
}

static int	key_pressed(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_all(game);
	if (keycode == W_KEY)
		game->player->key_up = TRUE;
	if (keycode == A_KEY)
		game->player->key_left = TRUE;
	if (keycode == S_KEY)
		game->player->key_down = TRUE;
	if (keycode == D_KEY)
		game->player->key_right = TRUE;
	if (keycode == R_ARROW)
		game->player->right_rotate = TRUE;
	if (keycode == L_ARROW)
		game->player->left_rotate = TRUE;
	/*else*/
	/*	ft_printf("key unknown press code :%d\n", keycode);*/
	return (0);
}

static int	key_released(int keycode, t_game *game)
{
	if (keycode == W_KEY)
		game->player->key_up = FALSE;
	if (keycode == A_KEY)
		game->player->key_left = FALSE;
	if (keycode == S_KEY)
		game->player->key_down = FALSE;
	if (keycode == D_KEY)
		game->player->key_right = FALSE;
	if (keycode == R_ARROW)
		game->player->right_rotate = FALSE;
	if (keycode == L_ARROW)
		game->player->left_rotate = FALSE;
	return (0);
}



int	looping_hook(t_game *game)
{
	ft_clear_background(game, MLX_BLACK);
	draw_map(game);
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
	game_loop(&game);
	return (0);
}
