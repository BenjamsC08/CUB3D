#include "cub3d.h"

static int	prealable_check(t_game *game, char c, int y, int x)
{
	if (!ft_ischarset(c, "NSWE0123 "))
		return (0);
	if (ft_ischarset(c, "NSWE") && !game->data_desc->player)
	{
		game->data_desc->player = c;
		game->data_desc->player_x = x;
		game->data_desc->player_y = y;
	}
	else if (ft_ischarset(c, "NSWE") && game->data_desc->player)
		return (0);
	return (1);
}

static int	check_char(t_game *game, char **map, int j, int i)
{
	if (!prealable_check(game, map[j][i], j, i))
		return (ft_dprintf(2, "0"), 0);
	if (j == 0 || i == 0 || j == game->data_desc->nb_line - 1 || (t_uint)i == ft_strlen(map[j]))
	{
		if (map[j][i] != '1' && !ft_iswhitespace(map[j][i]))
			return (ft_dprintf(2, "1"), 0);
		else
			return (1);
	}
	else if (ft_iswhitespace(map[j][i]))
	{
		if (map[j][i - 1] && !ft_ischarset(map[j][i-1], "1 "))
			return (ft_dprintf(2, "20"), 0);
		if (map[j][i + 1] && !ft_ischarset(map[j][i+1], "1 "))
			return (ft_dprintf(2, "21"), 0);
		if (map[j - 1][i] && !ft_ischarset(map[j-1][i], "1 "))
			return (ft_dprintf(2, "22"), 0);
		if (map[j + 1][i] && !ft_ischarset(map[j+1][i], "1 "))
			return (ft_dprintf(2, "23"), 0);
	}
	else if (ft_ischarset(map[j][i], "023NSWE"))
	{
		if ((!map[j][i - 1] || ft_iswhitespace(map[j][i - 1]))
			|| (!map[j][i + 1] || ft_iswhitespace(map[j][i + 1]))
			|| (!map[j - 1][i] || ft_iswhitespace(map[j - 1][i]))
			|| (!map[j + 1][i] || ft_iswhitespace(map[j + 1][i])))
			return (ft_dprintf(2, "3"), 0);
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
	while (map[j] && j < game->data_desc->nb_line)
	{
		i = 0;
		while (map[j][i] && map[j][i] != '\n' )
		{
			if (!check_char(game, map, j, i))
				return (error_map(map,j, i));
			i++;
		}
		j++;
	}
	free_strs(map);
	if (!game->data_desc->player)
		return (not_a_good_file(MAP));
	return (1);
}

static int	extract_loop(char ***ptr_map, char *line, int *max)
{
	char **map;
	int l;

	map = *ptr_map;
	if (!ft_strcmp(line, "\n"))
		return (free_strs(map), free(line), 0);
	l = ft_strlen(line);
	if (l > *max)
		*max = l - 1;
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
	int	  length;
	int i;

	line = get_next_line(fd);
	length = 0;
	i = 0;
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
		if (!extract_loop(&map, line, &length))
			return (0);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	// map = ft_strsfadd(map, "11111");
	game->data_desc->map = ft_add_strs_gc(game->gc_head, map);
	game->data_desc->line_length = length;
	game->data_desc->nb_line = i;
	return (check_map(game));
}
