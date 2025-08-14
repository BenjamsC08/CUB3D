/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_charset.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 04:39:27 by benjamsc          #+#    #+#             */
/*   Updated: 2025/05/28 04:39:27 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	is_in_charset(char c, const char *charset)
{
	char	*cs;

	cs = (char *)charset - 1;
	while (*(++cs))
	{
		if (*cs == c)
			return (1);
	}
	return (0);
}

char	*ft_remove_charset(char *str, const char *charset)
{
	char	*dest;
	char	*d;

	dest = ft_calloc(sizeof(char), ft_strlen(str) + 1);
	if (!dest)
		return (NULL);
	d = dest;
	while (*str)
	{
		if (!is_in_charset(*str, charset))
			*(d++) = *str;
		str++;
	}
	return (dest);
}
