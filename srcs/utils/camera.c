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

void	compute_cam_vectors(t_player *player, t_vec *dir_vec, t_vec *plane_vec)
{
	float	fov_half_tangent;

	dir_vec->x = cosf(player->angle);
	dir_vec->y = sinf(player->angle);
	fov_half_tangent = tanf((FOV_DEG * DEGREE) * 0.5f);
	plane_vec->x = -dir_vec->y * fov_half_tangent;
	plane_vec->y = dir_vec->x * fov_half_tangent;
}
