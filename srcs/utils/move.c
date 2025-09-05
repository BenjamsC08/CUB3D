/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 05:28:33 by mkerrien          #+#    #+#             */
/*   Updated: 2025/09/05 15:11:33 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	travelling(t_game *game, float dir_x, float dir_y, float move_speed)
{
	if (game->player->key_up == TRUE)
	{
		game->player->x += dir_x * move_speed;
		game->player->y += dir_y * move_speed;
	}
	if (game->player->key_down == TRUE)
	{
		game->player->x -= dir_x * move_speed;
		game->player->y -= dir_y * move_speed;
	}
	if (game->player->key_left == TRUE)
	{
		game->player->x -= -dir_y * move_speed;
		game->player->y -= dir_x * move_speed;
	}
	if (game->player->key_right == TRUE)
	{
		game->player->x -= dir_y * move_speed;
		game->player->y -= -dir_x * move_speed;
	}
}

static void	move(t_game *game)
{
	float	move_speed;
	float	dir_x;
	float	dir_y;

	move_speed = WALK_SPD;
	if (game->player->run == TRUE)
		move_speed = RUN_SPD;
	if ((game->player->key_up == TRUE || game->player->key_down == TRUE)
		&& (game->player->key_left == TRUE || game->player->key_right == TRUE))
		move_speed *= 0.5f;
	dir_x = cosf(game->player->angle);
	dir_y = sinf(game->player->angle);
	travelling(game, dir_x, dir_y, move_speed);
}

static void	apply_rotate(t_game *game)
{
	if (game->player->rot_left == TRUE)
		game->player->angle -= DEGREE;
	if (game->player->rot_right == TRUE)
		game->player->angle += DEGREE;
	if (game->player->angle > 2.0f * PI)
		game->player->angle -= 2.0f * PI;
	if (game->player->angle < 0.0f)
		game->player->angle += 2.0f * PI;
}

void	moves(t_game *game)
{
	apply_rotate(game);
	move(game);
}
