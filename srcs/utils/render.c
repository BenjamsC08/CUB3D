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

/**
 * @brief  Draw one vertical wall slice at a given screen column.
 *
 * Renders a vertical segment representing a wall hit by the ray at column
 * `screen_x`, using the perpendicular distance to compute projected height.
 * The segment is vertically centered and clamped to the window bounds.
 * Color depends on the side hit (e.g., darker for Y-side to suggest shading).
 *
 * @param  game        Global game context (framebuffer and draw helpers).
 * @param  screen_x    Screen column (0..W_WIDTH-1) where to draw the slice.
 * @param  perp_dist   Ray perpendicular distance used for perspective scaling.
 * @param  side_hit    Side flag from DDA (0 = X-side, 1 = Y-side).
 * @return None.
 *
 * @note   A tiny epsilon clamps very small distances to avoid division by zero.
 * @warning Uses flat colors; no texture sampling or z-buffering here.
 * @pre    Framebuffer is valid; W_WIDTH/W_HEIGHT/MLX_* constants are defined.
 * @post   A vertical line is drawn between draw_start and draw_end at screen_x.
 */
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

/**
 * @brief  Render a full frame by raycasting each screen column.
 *
 * For each column, sets up and runs DDA to find the first wall hit, computes
 * the perpendicular distance, and draws the corresponding vertical slice.
 * Camera basis vectors are computed once per frame from the player's state.
 *
 * @param  game  Global game context (player, map, raycast helpers, draw API).
 * @return None.
 *
 * @note   Columns without a tile hit are skipped (nothing drawn for that x).
 * @warning Runtime scales linearly with W_WIDTH.
 * @pre    Player position/angle and map data are initialized and consistent.
 * @post   The frame buffer contains a column-wise raycast of the current scene.
 */
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
