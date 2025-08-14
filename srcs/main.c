#include "cub3d.h"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (not_a_good_file(0));
	if (!good_file_ext(argv[1]))
		return (not_a_good_file(EXT));
	if (!load_cub_file(argv[1]))
		return (not_a_good_file(OPEN));

	return (0);
}
