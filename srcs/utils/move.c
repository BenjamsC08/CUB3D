/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 05:28:33 by mkerrien          #+#    #+#             */
/*   Updated: 2025/09/05 07:56:33 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <stdio.h> // DEBUG

void	move(t_game *game)
{
	float	speed;

	speed = WALK_SPD;
	if (game->player->run == TRUE)
		speed = RUN_SPD;
	if ((game->player->key_up || game->player->key_down) && (game->player->key_left || game->player->key_right))
		speed = speed / 2;
	if (game->player->key_up == TRUE)
		game->player->y -= speed;
	if (game->player->key_down == TRUE)
		game->player->y += speed * 0.75;
	if (game->player->key_left == TRUE)
		game->player->x -= speed;
	if (game->player->key_right == TRUE)
		game->player->x += speed;
}

void	rotate(t_game *game)
{
	dprintf(2, "DEBUG : player angle = %f\n", game->player->angle);
	if (game->player->rot_left == TRUE)
		game->player->angle += DEGREE;
	if (game->player->rot_right == TRUE)
		game->player->angle -= DEGREE;
	if (game->player->angle > 6.2831853072)
		game->player->angle -= 6.2831853072;
	if (game->player->angle < 0)
		game->player->angle += 6.2831853072;

}
