#include "libft.h"

void	ft_swap(int *a, int *b)
{
	if (*a == *b)
		return ;
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}
