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
	mlx_destroy_image(game->mlx, game->minimap->img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	ft_clear_gc(game->gc_head);
	exit (0);
}

static int	key_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_all(game);
<<<<<<< HEAD
=======
	if (keycode == CAPS_KEY)
	{
		if (game->minimap->pos == game->minimap->b_pos)
		{
			game->minimap->pos = CENTER;
			game->minimap->scale = 3;
		}
		else
		{
			game->minimap->pos = game->minimap->b_pos;
			game->minimap->scale = 1;
		}
		ft_clear_background(game, MLX_BLACK);
		draw_map(game, game->minimap->pos, game->minimap->scale);
	}
	else
		ft_printf("key unknown press code :%d\n", keycode);
	return (0);
}

static int	key_hook_released(int keycode, t_game *game)
{
	(void)keycode;
	(void)game;
	return (0);
}

void	temp_bg(t_game *game)
{
	void	*img;
	// char	*addr;
	int		x;
	int		y;

	img = mlx_xpm_file_to_image(game->mlx, "./assets/BG.xpm", &x, &y);
	// addr = mlx_get_data_addr(img, &game->data_img.bpp, &game->data_img.ll, &game->data_img.endian);
	mlx_put_image_to_window(game->mlx, game->win, img, 0, 0);
	mlx_destroy_image(game->mlx, img);

}

int	looping_hook(t_game *game)
{
	static int fc = 0;

	fc++;
	if (fc == 500000)
	{
		ft_clear_background(game, MLX_BLACK);
		draw_map(game, game->minimap->pos, game->minimap->scale);
		fc = 0;
	}
>>>>>>> f1f8776 (not finished draw rectangle)
	return (0);
}

int game_loop(t_game *game)
{
	draw_map(game, 0, 1);
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
		return (not_a_good_file(0), 1);
	if (!init_base(&game))
		return (1);
	if (!good_file_ext(argv[1]))
		return (close_all(&game), 1);
	if (!load_cub_file(&game, argv[1]))
		return (close_all(&game));
	game_loop(&game);
	// ft_print_strs(game.data_desc->map);
	// close_all(&game);
	// ft_printf("GREY %d\n", encode_rgb(150, 150 ,150));
	return (0);
}
