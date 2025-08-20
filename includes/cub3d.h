#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdlib.h>
# include "libft.h"

# include "cub3d_def.h"

/*
 *		  Utiles
*/ 
int		encode_rgb(t_byte r, t_byte g, t_byte b);
t_byte	get_r(int rgb);
t_byte	get_g(int rgb);
t_byte	get_b(int rgb);

// void	ft_pixel_put(t_game *game, int x, int y, int color);
<<<<<<< HEAD
void	ft_pixel_put(t_data_img data_img, char **addr, int pos[2], int color);
=======
void	ft_pixel_put(t_data_img data_img, char **addr, int pos[], int color);
void	ft_clear_background(t_game *game, int color);

>>>>>>> f1f8776 (not finished draw rectangle)

/*
*		  Parsing
*/
//base
int		good_file_ext(char *str);
int		convert_colors(char **strs, t_game *game, char c);
int		load_cub_file(t_game *game, char *str);
//error
int		not_a_good_file(int k);
int		error_map(char **map, int j, int i);
//line
int	check_line(char *line, t_game *game);
//map
int extract_map(t_game *game, int fd);
/*
*		  MINIMAP
*/
int draw_map(t_game *game, int pos, int scale);


#endif
