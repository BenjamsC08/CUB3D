#ifndef CUB3D_DEF_H
# define CUB3D_DEF_H

# define EXT 1
# define OPEN 2

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

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_gc	*gc;
	t_gc	**gc_head;
}				t_game;

#endif
