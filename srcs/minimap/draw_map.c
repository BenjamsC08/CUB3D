#include "cub3d.h"

void	move_minimap_player(t_game *game)
{
	int	speed;
	t_minimap *map;

	speed = 1;
	map = game->minimap;
	if (game->player->key_up == TRUE && map->player.y > 1)
		map->player.y -= speed;
	if (game->player->key_left == TRUE && map->player.x > 1)
		map->player.x -= speed;
	if (game->player->key_down == TRUE && map->player.y < (map->map.h - map->player.h) - 1)
		map->player.y += speed;
	if (game->player->key_right == TRUE && map->player.x < (map->map.w - map->player.w) - 1)
		map->player.x += speed;
}

void	draw_map(t_game *game)
{
	draw_rect(game, game->minimap->map, MLX_GREY);
	draw_rect(game, game->minimap->player, MLX_GREEN);
}

void	ft_minimap(t_game *game)
{
	move_minimap_player(game);
	draw_map(game);
}
