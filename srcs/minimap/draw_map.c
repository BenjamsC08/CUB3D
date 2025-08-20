#include "cub3d.h"

void move_minimap_player(t_game *game)
{
    float speed;
    float angle_speed;
    float cos_angle;
    float sin_angle;
    t_minimap *map;

    speed = 1.5;
    angle_speed = 0.01;
    cos_angle = cos(game->player->angle);
    sin_angle = sin(game->player->angle);
    map = game->minimap;

    if (game->player->left_rotate)
        game->player->angle -= angle_speed;
    if (game->player->right_rotate)
        game->player->angle += angle_speed;
    if (game->player->angle > 2 * PI)
        game->player->angle = 0;
    if (game->player->angle < 0)
        game->player->angle = 2 * PI;

    if (game->player->key_up == TRUE)
    {
        map->player.x += cos_angle * speed;
        map->player.y += sin_angle * speed;
    }
	if (game->player->key_down == TRUE)
    {
        map->player.x -= cos_angle * speed;
        map->player.y -= sin_angle * speed;
    }
    if (game->player->key_left == TRUE)
    {
        map->player.x += cos_angle * speed;
        map->player.y -= sin_angle * speed;
    }
    if (game->player->key_right == TRUE)
    {
        map->player.x -= cos_angle * speed;
        map->player.y += sin_angle * speed;
    }
}

t_bool touch(float px, float py, t_game *game)
{
	int x = px / BLOCK;
	int y = py / BLOCK;
	if (!game->data_desc->map[y] || !game->data_desc->map[y][x])
		return (TRUE);
	if (game->data_desc->map[y][x] == '1')
		return (TRUE);
	return (FALSE);
}


void	draw_line(t_game *game, float start_x, int i)
{
	(void) i;
    float cos_angle = cos(start_x);
    float sin_angle = sin(start_x);
	float ray_x = game->minimap->player.x;
	float ray_y = game->minimap->player.y;

	if (ray_x < 0 || ray_x >= W_WIDTH || ray_y < 0 || ray_y >= W_HEIGHT)
		return ;
	while (!touch(ray_x, ray_y , game))
	{
		ft_pixel_put(game, ray_x, ray_y, MLX_YELLOW);
		ray_x += cos_angle;
		ray_y += sin_angle;
	}
}

void	draw_ray(t_game *game)
{
	float fraction;
	float start_x;
	int i;

	fraction = PI / 3 / W_WIDTH;
	start_x = game->player->angle - PI / 6;
	i = 0;
	while (i < W_WIDTH)
	{
		draw_line(game, start_x, i);
		start_x += fraction;
		i++;
	}

}

void	draw_wall(t_game *game)
{
	char  **map;
	t_rect r;

	map = game->data_desc->map;
	for (int y = 0; map[y]; y++)
	{
		for (int x = 0; map[y][x]; x++)
		{
			if (map[y][x] == '1')
			{
				r.x = 1 + x * BLOCK;
				r.y = 1 + y * BLOCK;
				r.w = BLOCK;
				r.h = BLOCK;
				draw_rect(game, r, MLX_RED);
			}
		}

	}
}

void	draw_map(t_game *game)
{
	/*draw_rect(game, game->minimap->map, MLX_GREY);*/
	draw_rect(game, game->minimap->player, MLX_GREEN);
	draw_wall(game);
	draw_ray(game);
}

void	ft_minimap(t_game *game)
{
	move_minimap_player(game);
	draw_map(game);
}
