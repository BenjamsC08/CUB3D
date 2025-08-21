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

# define BLOCK 16

# define U_ARROW 65362
# define L_ARROW 65361
# define R_ARROW 65363
# define D_ARROW 65364
# define W_KEY 119
# define A_KEY 97
# define D_KEY 100
# define S_KEY 115
# define ESC 65307
# define CAPS 65293

# define TOP_RIGHT 0
# define TOP_LEFT 1
# define CENTER 2

# define MLX_BLACK 0
# define MLX_WHITE 16777215
# define MLX_WHITE1 16119285
# define MLX_RED 16711680
# define MLX_GREEN 65280
# define MLX_BLUE 255
# define MLX_YELLOW 16187136
# define MLX_ORANGE 16075047
# define MLX_PURPLE 10160621
# define MLX_GREY 9868950


typedef struct s_rect
{
	int x;
	int y;
	int w;
	int h;
}		t_rect;

typedef struct s_data_img
{
	int		bpp;
	int		ll;
	int		endian;
	void	*img;
	char	*addr;
}			t_data_img;

typedef struct s_data_desc
{
	char	*path_no;
	char	*path_so;
	char	*path_we;
	char	*path_ea;
	t_byte	floor_color;
	t_byte	ceiling_color;
	t_bool	player;
	int		player_y;
	int		player_x;
	char	**map;
	int		line_length;
	int		nb_line;
}			t_data_desc;

typedef struct s_player
{
	float	x;
	float	y;
	float	angle;
	t_bool	key_up;
	t_bool	key_down;
	t_bool	key_left;
	t_bool	key_right;
	t_bool	left_rotate;
	t_bool	right_rotate;
}		  t_player;

typedef struct s_minimap
{
	t_rect map;
	// t_rect player;
}			t_minimap;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_gc		*gc;
	t_gc		**gc_head;
	t_data_desc	*data_desc;
	t_data_img	*data_img;
	t_player	*player;
	t_minimap	*minimap;
}				t_game;

#endif
