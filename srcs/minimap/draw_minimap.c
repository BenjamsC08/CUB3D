/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 01:38:54 by mkerrien          #+#    #+#             */
/*   Updated: 2025/09/05 15:17:47 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief  Draw one row of the minimap.
 *
 * Renders a single map row onto the minimap by iterating over each cell
 * and painting a filled or outlined rectangle depending on its content.
 * Tile size is defined by BLOCK; screen coordinates are derived from
 * (col, row) * BLOCK. Walls ('1'), closed doors ('2'), opened doors ('3'),
 * and player spawns ('N','S','W','E') use different colors/styles.
 *
 * @param  game  Global game context (MLX handles, map, player).
 * @param  map   Null-terminated 2D char array representing the map.
 * @param  row   Zero-based row index to draw.
 * @return None.
 *
 * @note   Expects map[row] to be a null-terminated C string.
 * @warning No bounds check on row vs map height; caller must ensure validity.
 * @pre    game, game->data_desc, and drawing helpers must be initialized.
 * @post   The specified row is painted on the minimap image/window.
 */
static void	draw_minimap_row(t_game *game, const char **map, int row)
{
	t_rect	cell;
	int		col;

	cell.w = BLOCK;
	cell.h = BLOCK;
	col = 0;
	while (map[row][col])
	{
		cell.x = col * BLOCK;
		cell.y = row * BLOCK;
		if (map[row][col] == '1')
			draw_frect(game, cell, MLX_GREY);
		if (map[row][col] == '2')
			draw_frect(game, cell, MLX_BORDEAUX);
		if (map[row][col] == '3')
			draw_rect(game, cell, MLX_BORDEAUX);
		if (ft_ischarset(map[row][col], "NSWE"))
			draw_rect(game, cell, MLX_PURPLE);
		col++;
	}
}

/**
 * @brief  Draw the full minimap.
 *
 * Iterates over all rows of the loaded map and delegates per-row
 * rendering to draw_minimap_row(). When finished, draws a
 * rectangle of a certain color framing the minimap area.
 *
 * @param  game  Global game context (provides map and MLX drawing).
 * @return None.
 *
 * @note   Uses game->data_desc->map as the source; assumed null-terminated.
 * @warning Relies on valid dimensions and a properly allocated minimap rect.
 * @pre    Minimap geometry must be set (see init_minimap()).
 * @post   The minimap is fully rendered and outlined on screen.
 */
void	draw_minimap(t_game *game)
{
	const char	**map = (const char **)game->data_desc->map;
	int			row;

	row = -1;
	while (map[++row])
		draw_minimap_row(game, map, row);
	draw_rect(game, game->minimap->minimap, MLX_YELLOW);
}

/**
 * @brief  Initialize the minimap geometry to the window size.
 *
 * Sets the minimap rectangle origin to (0,0) and sizes it to the
 * full window dimensions (W_WIDTH x W_HEIGHT). This defines the area
 * later used by draw_minimap() for framing and placement.
 *
 * @param  game  Global game context containing the minimap struct.
 * @return None.
 *
 * @note   This only sets the rectangle; it does not allocate images.
 * @warning Assumes game->minimap is allocated and not NULL.
 * @pre    game and game->minimap must be valid pointers.
 * @post   game->minimap->minimap reflects the window-sized rectangle.
 */
void	init_minimap(t_game *game)
{
	game->minimap->minimap.x = 0;
	game->minimap->minimap.y = 0;
	game->minimap->minimap.w = W_WIDTH;
	game->minimap->minimap.h = W_HEIGHT;
}
