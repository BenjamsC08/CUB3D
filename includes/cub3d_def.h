#ifndef CUB3D_DEF_H
# define CUB3D_DEF_H

# include <pthread.h>

# define EXT 1
# define OPEN 2
# define BAD_COLOR 3
# define BAD_IMAGE 4
# define LINE 5
# define MAP 6

# define W_WIDTH 2560
# define W_HEIGHT 1370

# define BLOCK 30


# define SPACE			32
# define A_KEY			97
# define D_KEY			100
# define M_KEY			109
# define S_KEY			115
# define W_KEY			119
# define BACKSPACE		65288
# define ESC			65307
# define L_ARROW		65361
# define U_ARROW		65362
# define R_ARROW		65363
# define D_ARROW		65364
# define PAD_4			65430
# define PAD_8			65431
# define PAD_6			65432
# define PAD_2			65433
# define SHIFT			65505
# define CAPS			65509


# define MLX_BLACK		0
# define MLX_BLUE		255
# define MLX_GREEN		65280
# define MLX_BORDEAUX	5836288
# define MLX_GREY		9868950
# define MLX_PURPLE		10160621
# define MLX_ORANGE		16075047
# define MLX_WHITE1		16119285
# define MLX_YELLOW		16187136
# define MLX_RED		16711680
# define MLX_WHITE		16777215

# define NORTH			'N'
# define SOUTH			'S'
# define EAST			'E'
# define WEST			'W'

# define WALK_SPD		2.0f
# define RUN_SPD		4.0f

# define DEGREE			0.0174532925f

# define FOV_DEG		70.0f


typedef pthread_mutex_t t_mtx;

typedef struct s_vec
{
	float		x;
	float		y;
}				t_vec;

typedef struct s_ray
{
	t_vec		dir;     /* ray direction (en unites grille)    */
	t_vec		delta;   /* deltaDistX/Y                        */
	t_vec		side;    /* sideDistX/Y                         */
	int			mapx;    /* cellule X en DDA                    */
	int			mapy;    /* cellule Y en DDA                    */
	int			stepx;   /* +1 / -1                             */
	int			stepy;   /* +1 / -1                             */
	int			side_hit;/* 0: mur vertical, 1: mur horizontal  */
	char		tile;    /* 1 / 2 frappe (ou 0 si out of map)   */
}				t_ray;

typedef struct s_rect
{
	int			x;
	int			y;
	int			w;
	int			h;
}				t_rect;

typedef struct s_timer
{
	t_uint	  start_time;
	t_uint	  max_time;
	t_uint	  time;
	t_bool	  run;
	pthread_t thread;
	t_mtx	  *mtx_time;
	t_mtx	  *mtx_run;
}			  t_timer;

typedef struct s_data_img
{
	int			bpp;
	int			ll;
	int			endian;
	void		*img;
	char		*addr;
}				t_data_img;

typedef struct s_data_desc
{
	char		*path_no;
	char		*path_so;
	char		*path_we;
	char		*path_ea;
	t_byte		floor_color;
	t_byte		ceiling_color;
	char		player;
	int			player_y;
	int			player_x;
	char		**map;
	int			line_length;
	int			nb_line;
}				t_data_desc;

typedef struct s_player
{
	float		x;
	float		y;
	float		angle;
	t_bool		run;
	t_bool		key_up;
	t_bool		key_down;
	t_bool		key_left;
	t_bool		key_right;
	t_bool		rot_left;
	t_bool		rot_right;
}				t_player;

typedef struct s_minimap
{
	t_bool		disp_map;
	t_rect		map;
	t_rect		minimap;
}				t_minimap;

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
	t_timer		*timer;
	int			***tab_num;
}				t_game;

#endif
