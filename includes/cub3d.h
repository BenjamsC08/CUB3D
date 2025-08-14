#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdlib.h>
# include "libft.h"

# include "cub3d_def.h"

/*
*		  Parsing
*/
int	not_a_good_file(int k);
int	good_file_ext(char *str);
int load_cub_file(char *str);

#endif
