/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 05:28:33 by mkerrien          #+#    #+#             */
/*   Updated: 2025/09/05 06:49:15 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move(t_game *game)
{
	int	speed;

	speed = WALK_SPD;
	if (game->player->run == TRUE)
		speed = RUN_SPD;
	if (game->player->key_up == TRUE)
		// monter
		game->player->y -= speed;
	if (game->player->key_down == TRUE)
		// descendre
		game->player->y += speed;
	if (game->player->key_left == TRUE)
		// aller a gauche
		game->player->x -= speed;
	if (game->player->key_right == TRUE)
		// aller a droite
		game->player->x += speed;
}
