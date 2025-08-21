#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include "libft.h"

# include "cub3d_def.h"

/*													*/
/*						Utiles						*/
/*													*/

//						Colors
int		encode_rgb(t_byte r, t_byte g, t_byte b);
t_byte	get_r(int rgb);
t_byte	get_g(int rgb);
t_byte	get_b(int rgb);

//						Disp
void	ft_pixel_put(t_game *game, int x, int y, int color);
void	ft_clear_background(t_game *game, int color);
//						Figures
t_rect	get_rect(int x, int y, int width, int height);
void	draw_rect(t_game *game, t_rect rect, int color);

/*													*/
/*						Parsing						*/
/*													*/
int		init_parser(t_game *game);
//						Base
int		good_file_ext(char *str);
int		convert_colors(char **strs, t_game *game, char c);
int		load_cub_file(t_game *game, char *str);
//						Error
int		not_a_good_file(int k);
int		error_map(char **map, int j, int i);
//						Line
int		check_line(char *line, t_game *game);
//						Map
int		extract_map(t_game *game, int fd);

/*													*/
/*						Minimap						*/
/*													*/
int		init_minimap(t_game *game);
//						Draw
void	draw_map(t_game *game);
void	draw_minimap(t_game *game);

/*													*/
/*						INIT						*/
/*													*/
int		init_base(t_game *game);

/*													*/
/*						DESTROY						*/
/*													*/
int  close_all(t_game *game);

#endif
