#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "fillit.h"

char g_solution[12][12];

int	main(int ac, char **av)
{
	char	*file;
	int		len;
	char	tet_array[27][18];
	int		fd;

	if (ac != 2)
		return (0);
	file = av[1];
	if ((fd = open(file, O_RDONLY)) > 0)
	{
		if ((len = get_tets(fd, &tet_array)))
		{
			printf("Valid entry.\n");
			print_tets(&tet_array, len);
		}
		else
			printf("invalid entry.\n");
	}
	else 
		printf("file failed to read.");
	return (0);
}
