#include "cub3d.h"

int	not_a_good_file(int k)
{
	ft_dprintf(2, "Error\n");
	if (k == 0)
		ft_dprintf(2, "Incorrect number of arguments\n");
	if (k == EXT)
		ft_dprintf(2, "Bad extension file\n");
	if (k == OPEN)
		ft_dprintf(2, "Cannot open/read descriptor\n");
	if (k == BAD_COLOR)
		ft_dprintf(2, "Bad color in descriptor format accepted 'RRR,GGG,BBB' in decimal\n");
	if (k == BAD_IMAGE)
		ft_dprintf(2, "Cannot open image path in descriptor. Check if file exists.\n");
	if (k == LINE)
		ft_dprintf(2, "Something wrong with your descriptor before the map.\n");
	if (k == MAP)
		ft_dprintf(2, "Something wrong with your descriptor in the map.\n");
	return (0);
}

int error_map(char **map, int j, int i)
{
	ft_dprintf(2,"Error\n");
	ft_dprintf(2,"Something wrong in the map check this char `%c' in pos x:%d, y:%d\n", map[j][i], i, j);
	free_strs(map);
	return (0);
}
