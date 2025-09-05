#include "libft.h"

void	ft_free_2d_int(int **tab, int y)
{
	int i;

	i = -1;
	while (++i < y && tab[i])
		free(tab[i]);
	free(tab);
}

