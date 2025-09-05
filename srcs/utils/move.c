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

/**
 * @brief  Apply forward/backward and strafing movement based on pressed keys.
 *
 * Moves the player along the facing direction (forward/backward) and along
 * its perpendicular (left/right strafe) using the provided step vector and
 * speed. This function does not perform collision checks.
 *
 * @param  game        Global game context with player position and key states.
 * @param  dir_x       Cosine of the player angle (forward X component).
 * @param  dir_y       Sine of the player angle (forward Y component).
 * @param  move_speed  Movement speed in world units per tick.
 * @return None.
 *
 * @note   Strafing uses the perpendicular vector (-dir_y, dir_x).
 * @warning No wall clipping prevention here; call with prior collision tests
 *          or post-correct position elsewhere if needed.
 * @pre    Key states are up-to-date for the current frame.
 * @post   Player (x,y) is updated according to movement inputs.
 */
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

/**
 * @brief  Determines the movement speed (walk/run/diagonal) and moves the player.
 *
 * Selects the current movement speed (WALK_SPD or RUN_SPD), applies a penalty
 * for diagonal and backward movements, calculates the orientation direction, and delegates the
 * actual movement to travelling(). Collisions are not handled here.
 *
 * @param  game  Global game context with player state and keyboard inputs.
 * @return None.
 *
 * @note   Diagonal movement reduces speed by half in order to limit the resulting speed.
 * @warning Without collision checking, the player can walk through walls.
 * @pre    The player's angle and run/key indicators are valid for this frame.
 * @post   The player's coordinates are updated based on the active movement keys.
 */
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

/**
 * @brief  Apply discrete rotation to the player and wrap the angle to [0, 2π).
 *
 * Rotates the player by a fixed step (DEGREE) to the left/right depending on
 * key inputs, then normalizes the angle to stay within one full turn.
 *
 * @param  game  Global game context with player angle and rotation key states.
 * @return None.
 *
 * @note   Uses simple additive rotation; no smoothing or acceleration.
 * @warning Angle wrapping assumes PI and 2*PI constants are consistent.
 * @pre    Rotation key states are current for this frame.
 * @post   player->angle is updated and wrapped into [0, 2π).
 */
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

/**
 * @brief  Orchestrate per-frame player input: rotate first, then move.
 *
 * Applies rotation from current inputs and then processes translation based on
 * movement keys. Splitting rotation and translation improves readability and
 * mirrors common FPS input handling.
 *
 * @param  game  Global game context with player/input and world references.
 * @return None.
 *
 * @note   Collision (if any) should be integrated in the move path or after it.
 * @warning Order matters: rotation before movement changes forward/strafe axes.
 * @pre    Input flags for this tick have been collected.
 * @post   Player angle and position reflect inputs for the current frame.
 */
void	moves(t_game *game)
{
	apply_rotate(game);
	move(game);
}
