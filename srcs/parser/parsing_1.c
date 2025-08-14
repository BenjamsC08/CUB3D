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



// int	check_line(char *line)
// {
// 	if (ft_strncmp(line,"NO ", 3) && ft_strncmp(line,"SO ", 3) && ft_strncmp(line,"WE ", 3) && ft_strncmp(line,"EA ", 3)
// 		&& ft_strncmp(line,"F ", 2) && ft_strncmp(line,"C ", 2))
// 		return (1);
// 	if (!ft_strncmp(line,"NO ", 3))
// 	{
// 		// check and load path North texture
// 	}
// 	if (!ft_strncmp(line,"SO ", 3))
// 	{
// 		// check and load path South texture
// 	}
// 	if (!ft_strncmp(line,"WE ", 3))
// 	{
// 		// check and load path West texture
// 	}
// 	if (!ft_strncmp(line,"EA ", 3))
// 	{
// 		// check and load path East texture
// 	}
// 	if (!ft_strncmp(line,"F ", 2))
// 	{
// 		// check and load Floor colors
// 	}
// 	if (!ft_strncmp(line,"C ", 2))
// 	{
// 		// check and load Celling colors
// 	}
// 	return (0);
//
// }
//
// int	check_file(int fd)
// {
// 	char	*line;
// 	int		i;
// 	int		k;
//
// 	i = 0;
// 	k = 0;
// 	line = get_next_line(fd);
// 	if (!line)
// 		return (0);
// 	while (line)
// 	{
// 		if (ft_strcmp(line, "\n"))
// 		{
// 			k = check_line(line);
// 			if (k)
// 				return (k);
// 			i++;
// 		}
// 		free(line);
// 		if (i >= 5)
// 			check_map(fd);
// 		else
// 			line = get_next_line(fd);
// 	}
// }

int load_cub_file(char *str)
{
	int		fd;
	char	*buffer;

	buffer = NULL;
	fd = open(str, O_RDONLY);
	if (fd < 0 || read(fd, buffer, 0) < 0)
		return (0);
	// check_file(fd);
	close (fd);
	return (1);
}
