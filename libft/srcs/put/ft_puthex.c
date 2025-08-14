
#include "libft.h"

int	ft_puthex(unsigned int nbr, char type)
{
	char	*s;
	char	*s1;
	int		len;

	if (nbr == 0)
		return (ft_putchar('0'));
	s1 = ft_xtoa(nbr, type);
	s = s1;
	if (nbr == 0)
		return (ft_putchar('0'));
	while (*s1)
		write(1, (s1++), 1);
	len = ft_strlen(s);
	free(s);
	return (len);
}

int	ft_puthex_fd(int fd, unsigned int nbr, char type)
{
	char	*s;
	char	*s1;
	int		len;

	if (nbr == 0)
		return (ft_putchar_fd(fd, '0'));
	s1 = ft_xtoa(nbr, type);
	s = s1;
	if (nbr == 0)
		return (ft_putchar_fd(fd, '0'));
	while (*s1)
		write(fd, (s1++), 1);
	len = ft_strlen(s);
	free(s);
	return (len);
}
