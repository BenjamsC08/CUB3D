#include "libft.h"

int **ft_1d_to_2d_int(const int *tab, int rows, int cols)
{
	int **out;

	out = ft_calloc(sizeof(int *), rows);
	if (!out)
		return (NULL);
    for (int i = 0; i < rows; i++)
    {
		out[i] = ft_calloc(sizeof(int), cols);
		if (!out[i])
			return (ft_free_2d_int(out, cols), NULL);
        for (int j = 0; j < cols; j++)
            out[i][j] = tab[i * cols + j];
    }
	return (out);
}

