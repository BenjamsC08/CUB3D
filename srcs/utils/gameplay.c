/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 05:29:11 by mkerrien          #+#    #+#             */
/*   Updated: 2025/09/06 05:50:41 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	back_to_home(t_game *game)
{
	game->player->x = (game->data_desc->player_x * BLOCK) + (BLOCK / 2);
	game->player->y = (game->data_desc->player_y * BLOCK) + (BLOCK / 2);
}

void	set_angle(t_game *game, int keycode)
{
if (keycode == PAD_2)
		game->player->angle = 0.5f * PI;
	else if (keycode == PAD_4)
		game->player->angle = PI;
	else if (keycode == PAD_8)
			game->player->angle = -0.5f * PI;
	else if (keycode == PAD_6)
		game->player->angle = 0.0f;
}
