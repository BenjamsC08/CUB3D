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

int load_cub_file(char *str)
{
	int		fd;
	char	*buffer;

	buffer = NULL;
	fd = open(str, O_RDONLY);
	if (fd < 0 || read(fd, buffer, 0) < 0)
		return (0);
	close (fd);
	return (1);
}
