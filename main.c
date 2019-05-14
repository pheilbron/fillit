/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 12:56:26 by pheilbro          #+#    #+#             */
/*   Updated: 2019/05/13 16:30:36 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	g_solution[12][12];

int	main(int argc, char **argv)
{
	int		fd;
	int		len;
	int		pos[2];
	int		size;
	char	tetrominos[27][18];

	clear_board();
	pos[0] = 0;
	pos[1] = 0;
	if (argc != 2)
		write(1, "usage: ./fillit source_file\n", 28);
	else if ((fd = open(argv[1], O_RDONLY)) > 0)
	{
		if ((len = get_tets(fd, &tetrominos)))
		{
			size = solve(tetrominos, 0, pos, start_size(len));
			print_solution(size);
		}
		else
			write(1, "error\n", 6);
	}
	else
		write(1, "error\n", 6);
	return (0);
}
