/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 08:48:23 by benjamsc          #+#    #+#             */
/*   Updated: 2025/08/14 09:05:23 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	not_a_good_file(int k)
{
	ft_dprintf(2, "Error\n");
	if (k == 0)
		ft_dprintf(2, "incorrect number of arguments\n");
	if (k == EXT)
		ft_dprintf(2, "Bad extension file\n");
	if (k == OPEN)
		ft_dprintf(2, "Error when trying to open/read descriptor\n");
	return (1);
}

int	good_file_ext(char *str)
{
	while (*str)
	{
		if (*str == '.' && !ft_strcmp(++str, "cub"))
			return (1);
		str++;
	}
	return (0);
}

int	try_to_open_image(t_game *game, char *path_img)
{
	int x;
	int y;

	x = W_WIDTH;
	x = W_HEIGHT;
	ptr = mlx_xpm_file_to_image(game->mlx, path_img, &y, &x);
	if (!ptr)
		return (free_tabtab(list), 0);
	mlx_destroy_image(game->mlx, ptr);
}

char	*extract_path_texture(t_game *game, char *line)
{
	if (!ftstrncmp(line,"F ", 2) || !ftstrncmp(line,"C ", 2))
		return (NULL);
	line += 3;
	if (!line)
		return (NULL);
	while (*line && ft_iswhitespace(*line))
		line++;
	if (!line)
		return (NULL);
	if (!try_to_open_image(game, line))
		return (NULL);
	return (line);
}

int convert_colors(char **strs, t_game *game, char c)
{
	int i;
	int tmp;
	int color;

	i = 0;
	tmp = 0;
	color = 0;
	while (i < 3)
	{
		tmp = ft_atoi(strs[i]);
		if (tmp < 0 || tmp > 255)
			return (0);
		color += tmp;
		if (i != 2)
			color <<= 8;
		i++;
	}
	if (c == 1)
		game->data_desc->floor_color = color;
	else
		game->data_desc->celling_color = color;
	return (1);
}

int extract_color(t_game *game, char *line)
{
	char **strs;
	char c;

	if (!ftstrncmp(line,"F ", 2))
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
	strs = ft_split(line, ",");
	if (!strs)
		return (0);
	if (ft_strslen(strs) != 3)
		return (free_strs(strs), 0);
	if (!convert_colors(strs, game, c))
		return (free_strs(strs), 0);
	return (1);
}

int	check_line(char *line, t_game *game)
{
	char	*temp;

	temp = NULL;
	if (ft_strncmp(line,"NO ", 3) && ft_strncmp(line,"SO ", 3) && ft_strncmp(line,"WE ", 3) && ft_strncmp(line,"EA ", 3)
		&& ft_strncmp(line,"F ", 2) && ft_strncmp(line,"C ", 2))
		return (0);
	if (!ft_strncmp(line,"F ", 2) || !ft_strncmp(line,"C ", 2) && extract_color(game, line))
		return (1);
	else
	{
		temp = extract_path_texture(game, line);
		if (!temp)
			return (2);
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

int	check_file(t_game *game, int fd)
{
	char	*line;
	int		i;
	int		k;

	i = 0;
	k = 0;
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line)
	{
		if (ft_strcmp(line, "\n"))
		{
			k = check_line(line, game);
			if (k)
				return (k);
			i++;
		}
		free(line);
		if (i >= 5)
			check_map(fd);
		else
			line = get_next_line(fd);
	}
}

int load_cub_file(t_game *game, char *str)
{
	int		fd;
	char	*buffer;

	buffer = NULL;
	fd = open(str, O_RDONLY);
	if (fd < 0 || read(fd, buffer, 0) < 0)
		return (0);
	// check_file(game, fd);
	close (fd);
	return (1);
}
