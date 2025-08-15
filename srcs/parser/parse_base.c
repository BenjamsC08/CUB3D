#include "cub3d.h"

int	good_file_ext(char *str)
{
	while (*str)
	{
		if (*str == '.' && !ft_strcmp(++str, "cub"))
			return (1);
		str++;
	}
	return (not_a_good_file(EXT));
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
		game->data_desc->ceiling_color = color;
	return (1);
}

static int	check_file(t_game *game, int fd)
{
	char	*line;
	static int		i = 0;

	line = get_next_line(fd);
	if (!line)
		return (not_a_good_file(OPEN));
	while (line)
	{
		if (ft_strncmp(line, "\n", 1))
		{
			if (check_line(line, game))
				i++;
			else
				return (free(line), 0);
		}
		free(line);
		if (i > 5)
		{
			if (!extract_map(game, fd))
				return (0);
			break ;
		}
		line = get_next_line(fd);
	}
	return (1);
}

int load_cub_file(t_game *game, char *str)
{
	int		fd;
	char	*buffer;

	buffer = NULL;
	fd = open(str, O_RDONLY);
	if (fd < 0 || read(fd, buffer, 0) < 0)
		return (not_a_good_file(OPEN));
	 if (!check_file(game, fd))
		return (close(fd), 0);
	close (fd);
	return (1);
}
