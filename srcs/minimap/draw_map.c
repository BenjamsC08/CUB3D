#include "cub3d.h"

int draw_map(t_game *game, int pos, int scale)
{
	const int y = (W_HEIGHT/4) * scale;
	const int x = (W_WIDTH/6) * scale;

	(void)pos;
	game->minimap = ft_gcalloc(game->gc_head, sizeof(t_minimap));
	if (!game->minimap)
		return (1);
	game->minimap->img = mlx_new_image(game->mlx, x, y);
	game->minimap->addr = mlx_get_data_addr(game->minimap->img, &game->data_img->bpp, &game->data_img->ll, &game->data_img->endian);
	draw_rect(game, y, x);
	mlx_put_image_to_window(game->mlx, game->win, game->minimap->img, 0 ,0); // mettre le offset  ici et pas dans les image	
	return (0);
}


