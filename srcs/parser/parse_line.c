#include "cub3d.h"

static int	try_to_open_image(t_game *game, char *path_img)
{
	int x;
	int y;
	void *ptr;

	x = W_WIDTH;
	x = W_HEIGHT;
	ptr = mlx_xpm_file_to_image(game->mlx, path_img, &y, &x);
	if (!ptr)
		return (0);
	mlx_destroy_image(game->mlx, ptr);
	return (1);
}

static char	*extract_path_texture(t_game *game, char *line)
{
	char *str;

	str = ft_gc_addnode(game->gc_head, ft_remove_charset(line, "\n"));
	if (!str)
		return (NULL);
	str += 3;
	if (!str)
		return (NULL);
	while (*line && ft_iswhitespace(*str))
		str++;
	if (!str)
		return (NULL);
	if (!try_to_open_image(game, str))
		return (NULL);
	return (str);
}

static int extract_color(t_game *game, char *line)
{
	char **strs;
	char c;

	if (!ft_strncmp(line,"F ", 2))
		c = 1;
	else
		c = 2;
	line += 2;
	if (!line)
		return (0);
	while (*line && ft_iswhitespace(*line))
		line++;
	if (!line)
		return (0);
	strs = ft_split(line, ',');
	if (!strs)
		return (0);
	if (ft_strslen(strs) != 3)
		return (free_strs(strs), 0);
	if (!convert_colors(strs, game, c))
		return (free_strs(strs), 0);
	return (free_strs(strs), 1);
}

int	check_line(char *line, t_game *game)
{
	char *temp;

	temp = NULL;
	if (ft_strncmp(line,"NO ", 3) && ft_strncmp(line,"SO ", 3) 
		&& ft_strncmp(line,"WE ", 3) && ft_strncmp(line,"EA ", 3)
		&& ft_strncmp(line,"F ", 2) && ft_strncmp(line,"C ", 2))
		return (not_a_good_file(OPEN));
	else if (!ft_strncmp(line,"F ", 2) || !ft_strncmp(line,"C ", 2))
	{
		if (!extract_color(game, line))
			return (not_a_good_file(BAD_COLOR));
	}
	else
	{
		temp = extract_path_texture(game, line);
		if (!temp)
			return (not_a_good_file(BAD_IMAGE));
		if (!ft_strncmp(line,"NO ", 3))
			game->data_desc->path_no = ft_gc_addnode(game->gc_head, ft_strdup(temp));
		if (!ft_strncmp(line,"SO ", 3))
			game->data_desc->path_so = ft_gc_addnode(game->gc_head, ft_strdup(temp));
		if (!ft_strncmp(line,"WE ", 3))
			game->data_desc->path_we = ft_gc_addnode(game->gc_head, ft_strdup(temp));
		if (!ft_strncmp(line,"EA ", 3))
			game->data_desc->path_ea = ft_gc_addnode(game->gc_head, ft_strdup(temp));
	}
	return (1);
}
