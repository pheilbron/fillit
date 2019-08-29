#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "fillit.h"

char g_solution[12][12];

void	print_tets(int len)
{
	int	i;
	int	tet_i;

	i = 0;
	tet_i = 0;
	while (tet_i < len)
	{
		printf("%cx%c\n", g_tets[tet_i][16] + '0', g_tets[tet_i][17] + '0');
		while (i < 16)
		{
			write(1, g_tets[tet_i] + i, 4);
			write(1, "\n", 1);
			i += 4;
		}
		if (tet_i + 1 != len)
			write(1, "\n", 1);
		i = 0;
		tet_i++;
	}
}

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
