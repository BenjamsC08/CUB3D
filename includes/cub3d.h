#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdlib.h>
# include "libft.h"

# include "cub3d_def.h"

/*
 *		  Utiles
*/ 
int		encode_trgb(t_byte t, t_byte r, t_byte g, t_byte b);
t_byte	get_t(int trgb);
t_byte	get_r(int trgb);
t_byte	get_g(int trgb);
t_byte	get_b(int trgb);
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

#endif
