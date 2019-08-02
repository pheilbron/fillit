#include <stdio.h>
#include <stdint.h>

int	main(void)
{
	char	*tet = "..........#..###";
	uint64_t	value = 0;

	for (int i = 0; i < 16; i++)
		if (tet[i] == '#')
			value |= (1UL << (63 - (((i / 4) * 16) + (i % 4))));
	printf("%llu\t%llx\n", value, value);
	return (0);
}
