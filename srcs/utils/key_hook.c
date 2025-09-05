/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 05:17:55 by mkerrien          #+#    #+#             */
/*   Updated: 2025/09/05 05:21:47 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/**/
/*static int	key_pressed2(int keycode, t_game *game)*/
/*{*/
/*	if (keycode == )*/
/*}*/

int	key_pressed(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_all(game);
	else if (keycode == W_KEY)
		game->player->key_up = TRUE;
	else if (keycode == A_KEY)
		game->player->key_left = TRUE;
	else if (keycode == S_KEY)
		game->player->key_down = TRUE;
	else if (keycode == D_KEY)
		game->player->key_right = TRUE;
	else if (keycode == M_KEY)
		game->minimap->disp_map = TRUE;
	else if (keycode == CAPS && game->minimap->disp_map == TRUE)
		game->minimap->disp_map = FALSE;
	else if (keycode == CAPS && game->minimap->disp_map == FALSE)
		game->minimap->disp_map = TRUE;
	else
		ft_printf("key unknown press code :%d\n", keycode);
	return (0);
}

int	key_released(int keycode, t_game *game)
{
	if (keycode == W_KEY)
		game->player->key_up = FALSE;
	if (keycode == A_KEY)
		game->player->key_left = FALSE;
	if (keycode == S_KEY)
		game->player->key_down = FALSE;
	if (keycode == D_KEY)
		game->player->key_right = FALSE;
	if (keycode == M_KEY)
		game->minimap->disp_map = FALSE;
	return (0);
}
