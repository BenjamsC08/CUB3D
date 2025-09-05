/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:35:10 by mkerrien          #+#    #+#             */
/*   Updated: 2025/09/05 14:43:02 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_vertical_slice(t_game *game, int screen_x, float perp_dist,
		int side_hit)
{
	int	line_height;
	int	draw_start;
	int	draw_end;
	int	screen_y;

	if (perp_dist < 0.000001f)
		perp_dist = 0.000001f;
	line_height = (int)((float)W_HEIGHT / perp_dist);
	draw_start = -line_height / 2 + W_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + W_HEIGHT / 2;
	if (draw_end >= W_HEIGHT)
		draw_end = W_HEIGHT - 1;
	screen_y = draw_start;
	while (screen_y <= draw_end)
	{
		if (side_hit == 1)
			ft_pixel_put(game, screen_x, screen_y, MLX_BORDEAUX);
		else
			ft_pixel_put(game, screen_x, screen_y, MLX_RED);
		screen_y++;
	}
}

void	render_frame(t_game *game)
{
	t_vec	dir_vec;
	t_vec	plane_vec;
	t_ray	ray;
	int		screen_x;
	float	perp_dist;

	compute_cam_vectors(game->player, &dir_vec, &plane_vec);
	screen_x = 0;
	while (screen_x < W_WIDTH)
	{
		ray_setup(game, &ray, screen_x);
		ray_run_dda(game, &ray);
		if (!ray.tile)
		{
			screen_x++;
			continue ;
		}
		perp_dist = ray_perp_dist(game, &ray);
		draw_vertical_slice(game, screen_x, perp_dist, ray.side_hit);
		screen_x++;
	}
}
