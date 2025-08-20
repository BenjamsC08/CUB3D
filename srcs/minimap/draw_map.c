#include "cub3d.h"

#define PLAYER_WIDTH 4

// void draw_player(t_game *game)
// {
// 	int x;
// 	int y;
// 	int i;
// 	int l;
//
// 	x = game->player->pos->x;
// 	y = game->player->pos->y;
// 	l = 0;
// 	while (l < PLAYER_WIDTH)
// 	{
// 		i = 0;
// 		while (i < PLAYER_WIDTH)
// 		{
//
// 		}
// 	}
// }

void	draw_rectangle(t_game *game, char **ptr_addr, int *pos[2], int dimension[], int color)
{
	int i;
	int j;

	(void)color;
	// addr = *ptr_addr;
	j = -1;
	while (++j < dimension[0])
	{
		i = -1;
		while (++i < dimension[1])
		{
			ft_pixel_put(game->data_img, ptr_addr, pos, MLX_RED);
		}
	}
	pos[0] = j;
	pos[1] = i;
}

// void draw_wall(t_game *game, void **ptr_img, char **ptr_addr, int start_pos[])
// {
// 	void	img;
// 	int		x;
// 	int		y;
//
// 	img = *ptr_img;
// }

static void	da_vinci(t_game *game, const int y, const int x)
{
	int i;
	int j;
	int	p[2];
	int d[2];

	d[0] = 10;
	d[1] = 10;
	j = -1;
	while (++j < y)
	{
		p[0] = j;
		i = -1;
		if (j == 10)
			draw_rectangle(game, addr, p, d, MLX_RED);
		while (++i < x)
		{
			p[1] = i;
			ft_pixel_put(game->data_img, &game->minimap->addr, p, MLX_GREY);
		}
	}

}

int draw_map(t_game *game, int pos, int scale)
{
	const int y = (W_HEIGHT/4) * scale;
	const int x = (W_WIDTH/6) * scale;

	(void)pos;
	game->minimap = ft_gcalloc(game->gc_head, sizeof(t_minimap));
	if (!game->minimap)
		return (1);
	game->minimap->img = mlx_new_image(game->mlx, x, y);
	game->minimap->addr = mlx_get_data_addr(game->minimap->img, &game->data_img.bpp, &game->data_img.ll, &game->data_img.endian);
	da_vinci(game, y, x);
	mlx_put_image_to_window(game->mlx, game->win, game->minimap->img, 0 ,0); // mettre le offset  ici et pas dans les image	
	return (0);
}

// int draw_map(t_game *game, int pos, int scale)
// {
// 	int	p[2];
// 	const int y = (W_HEIGHT/6) * scale;
// 	const int x = (W_WIDTH/6) * scale;
// 	(void)pos;
// 	game->minimap = ft_gcalloc(game->gc_head, sizeof(t_minimap));
// 	if (!game->minimap)
// 		return (1);
// 	game->minimap->img = mlx_new_image(game->mlx, x, y);
// 	game->minimap->addr = mlx_get_data_addr(game->minimap->img, &game->data_img.bpp, &game->data_img.ll, &game->data_img.endian);
// 	// ft_pixel_put(game, 600, 400, encode_trgb(0, 255,12,255));
// 	p[0] = -1;
// 	while (++p[0] > y)
// 	{
// 		p[1] = -1;
// 		while (++p[1] > x)
// 			ft_pixel_put(game->data_img, &game->minimap->addr, p, encode_trgb(0, 255,255,255));
// 		}
// 	mlx_put_image_to_window(game->mlx, game->win, game->minimap->img, W_WIDTH/2 , W_HEIGHT/2); // mettre le offset  ici et pas dans les image	
// 	return (0);
// }
