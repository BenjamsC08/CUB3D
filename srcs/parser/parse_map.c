#include "cub3d.h"

static int	prealable_check(t_game *game, char c)
{
	if (!ft_ischarset(c, "NSWE012 "))
		return (0);
	if (ft_ischarset(c, "NSWE") && !game->data_desc->pos)
		game->data_desc->pos = c;
	else if (ft_ischarset(c, "NSWE") && game->data_desc->pos)
		return (0);
	return (1);
}

static int	check_char(t_game *game, char **map, int j, int i)
{
	if (!prealable_check(game, map[j][i]))
		return (0);
	if ((j == 0 || i == 0) && (map[j][i] != '1' && !ft_iswhitespace(map[j][i])))
		return (1);
	else
		return (1);
	if (ft_iswhitespace(map[j][i]))
	{
		if ((map[j][i - 0] && map[j][i - 1] != '1')
			|| (map[j][i + 0] && map[j][i + 1] != '1')
			|| (map[j - 0][i] && map[j - 1][i] != '1')
			|| (map[j + 0][i] && map[j + 1][i] != '1'))
			return (0);
	}
	else if (map[j][i] == '1' || map[j][i] == '2' || ft_ischarset(map[j][i], "NSWE"))
	{
		if ((!map[j][i - 0] || ft_iswhitespace(map[j][i - 1]))
			|| (!map[j][i + 0] || ft_iswhitespace(map[j][i + 1]))
			|| (!map[j - 0][i] || ft_iswhitespace(map[j - 1][i]))
			|| (!map[j + 0][i] || ft_iswhitespace(map[j + 1][i])))
			return (0);
	}
	return (1);
}

static int check_map(t_game *game)
{
	int	i;
	int	j;
	char **map;

	j = 0;
	if (!game->data_desc->map || !*game->data_desc->map)
		return (0);
	map = ft_strsdup(game->data_desc->map);
	while (map[j])
	{
		i = 0;
		while (map[j][i] && map[j][i] != '\n')
		{
			if (!check_char(game, map, j, i))
				return (error_map(map,j, i));
			i++;
		}
		j++;
	}
	free_strs(map);
	return (1);
}

static int	extract_loop(char ***ptr_map, char *line)
{
	char **map;

	map = *ptr_map;
	if (!ft_strcmp(line, "\n"))
		return (free_strs(map), free(line), 0);
	if (!*map)
	{
		*map = ft_strdup(line);
		if (!*map)
			return (free(map), 0);
	}
	else
		map = ft_strsfadd(map, line);
	if (!map)
		return (free(line), 0);
	*ptr_map = map;
	return (1);
}

int extract_map(t_game *game, int fd)
{
	char *line;
	char **map;

	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line && !ft_strcmp(line, "\n"))
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		return (0);
	map = ft_calloc(2, sizeof(char *));
	if (!map)
		return (0);
	while (line)
	{
		if (!extract_loop(&map, line))
			return (0);
		free(line);
		line = get_next_line(fd);
	}
	game->data_desc->map = ft_add_strs_gc(game->gc_head, map);
	return (check_map(game));
}
