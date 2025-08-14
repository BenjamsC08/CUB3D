#include "libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putchar_fd(int fd, char c)
{
	write(fd, &c, 1);
	return (1);
}
