#include "cub3d.h"

static int init_mlx(t_game *game)
{
	game->mlx = ft_gc_addnode(game->gc_head, mlx_init());
	if (!game->mlx)
		return (ft_clear_gc(game->gc_head), 0);
	game->win = mlx_new_window(game->mlx, W_WIDTH, W_HEIGHT,
			"CUB3D");
	if (!game->win)
		return (ft_clear_gc(game->gc_head), 0);
	game->data_img = ft_gcalloc(game->gc_head, sizeof(t_data_img));
	if (!game->data_img)
		return (ft_clear_gc(game->gc_head), 0);
	game->data_img->img = mlx_new_image(game->mlx, W_WIDTH, W_HEIGHT);
	game->data_img->addr = mlx_get_data_addr(game->data_img->img, &game->data_img->bpp,
										  &game->data_img->ll,&game->data_img->endian);
	mlx_put_image_to_window(game->mlx, game->win, game->data_img->img, 0, 0);
	return (1);
}

int	init_player(t_game *game)
{
	game->player = ft_gcalloc(game->gc_head, sizeof(t_player));
	if (!game->player)
		return (0);
	return (1);
}

int	init_base(t_game *game)
{
	game->gc = init_gc();
	if (!game->gc)
		return (0);
	game->gc_head = &(game->gc);
	if (!init_mlx(game))
		return (ft_clear_gc(game->gc_head), 0);
	if (!init_parser(game))
		return (close_all(game), 0);
	if (!init_player(game))
		return (close_all(game), 0);
	if (!init_minimap(game))
		return (close_all(game), 0);
	return (1);
}
