#ifndef CUB3D_DEF_H
# define CUB3D_DEF_H

# define EXT 1
# define OPEN 2
# define BAD_COLOR 3
# define BAD_IMAGE 4
# define LINE 5
# define MAP 6

# define W_WIDTH 1280
# define W_HEIGHT 720

# define U_ARROW 65362
# define L_ARROW 65361
# define R_ARROW 65363
# define D_ARROW 65364
# define W_KEY 119
# define A_KEY 97
# define D_KEY 100
# define S_KEY 115
# define ESC 65307

typedef struct s_data_desc
{
	char	*path_no;
	char	*path_so;
	char	*path_we;
	char	*path_ea;
	t_byte	floor_color;
	t_byte	ceiling_color;
	char	**map;
}			t_data_desc;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_gc		*gc;
	t_gc		**gc_head;
	t_data_desc	*data_desc;
}				t_game;

#endif
