/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:45:05 by benjamsc          #+#    #+#             */
/*   Updated: 2024/11/11 21:45:07 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strlen_to(char *str, char c)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
	if (!*str)
		return (0);
	while (str[i] && str[i] != c)
		i++;
	return (i);
}
