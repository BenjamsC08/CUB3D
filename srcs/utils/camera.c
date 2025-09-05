/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:33:42 by mkerrien          #+#    #+#             */
/*   Updated: 2025/09/05 13:33:49 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief  Compute camera direction and plane vectors from player angle and FOV.
 *
 * Produces the forward direction vector (cos,sin) of the player and the
 * camera plane (perpendicular to direction) scaled by tan(FOV/2). These
 * vectors define the per-column ray directions across the screen.
 *
 * @param  player     Player state providing the current facing angle (radians).
 * @param  dir_vec    Output: normalized forward direction vector.
 * @param  plane_vec  Output: camera plane vector (perpendicular to dir_vec).
 * @return None.
 *
 * @note   FOV_DEG is converted to radians via DEGREE before calling tanf().
 * @warning Extremely wide FOVs (near 180°) make tan(FOV/2) blow up.
 * @pre    player is valid; DEGREE and FOV_DEG are consistent constants.
 * @post   dir_vec and plane_vec are set for use by per-column ray generation.
 */
void	compute_cam_vectors(t_player *player, t_vec *dir_vec, t_vec *plane_vec)
{
	float	fov_half_tangent;

	dir_vec->x = cosf(player->angle);
	dir_vec->y = sinf(player->angle);
	fov_half_tangent = tanf((FOV_DEG * DEGREE) * 0.5f);
	plane_vec->x = -dir_vec->y * fov_half_tangent;
	plane_vec->y = dir_vec->x * fov_half_tangent;
}
