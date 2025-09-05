#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdlib.h>
# include <float.h>
# include <math.h>
# include <sys/time.h>
# include "libft.h"

# include "cub3d_def.h"

/*													*/
/*						UTILS						*/
/*													*/
//						Colors
int		encode_rgb(t_byte r, t_byte g, t_byte b);
t_byte	get_r(int rgb);
t_byte	get_g(int rgb);
t_byte	get_b(int rgb);

//						Disp
void	ft_pixel_put(t_game *game, int x, int y, int color);
void	ft_clear_background(t_game *game, int color);
void	put_timer(t_game *game, t_uint size, int color, t_rect frame);
//						Figures
t_rect	get_rect(int x, int y, int width, int height);
void	draw_rect(t_game *game, t_rect rect, int color);
void	draw_frect(t_game *game, t_rect rect, int color);
//						Key hook
int		key_pressed(int keycode, t_game *game);
int		key_released(int keycode, t_game *game);
//						Moves/Rotations
void	moves(t_game *g);
//						Time
int		set_start_time(t_game *game);
t_uint	get_current_time(void);
int		start_time(t_game *game);
int		create_num(t_game *game);

/*													*/
/*						PARSING						*/
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
/*						MINIMAP						*/
/*													*/
void	init_map(t_game *game);
void	init_minimap(t_game *game);
//						Draw
void	draw_map(t_game *game);
void	draw_minimap(t_game *game);
//						Raycast
void	compute_cam_vectors(t_player *p, t_vec *dir, t_vec *plane);
void	draw_rays(t_game *game);
void	ray_setup(t_game *game, t_ray *ray, int screen_x);
void	ray_run_dda(t_game *game, t_ray *r);
void	render_frame(t_game *game);
float	ray_perp_dist(t_game *game, t_ray *r);

/*													*/
/*						INIT						*/
/*													*/
int		init_base(t_game *game);
int		init_player(t_game *game);

/*													*/
/*						DESTROY						*/
/*													*/
int		close_all(t_game *game);

#endif
