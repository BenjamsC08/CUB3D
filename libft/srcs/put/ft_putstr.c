#include "libft.h"

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (*str)
		len += ft_putchar(*(str++));
	return (len);
}

int	ft_putstr_fd(int fd, char *s)
{
	char	*s1;
	int		len;

	len = 0;
	s1 = s - 1;
	while (*(++s1))
		len += write(fd, s1, 1);
	return (len);
}
