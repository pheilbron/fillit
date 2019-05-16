/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 12:56:26 by pheilbro          #+#    #+#             */
/*   Updated: 2019/05/16 15:49:16 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	g_tets[27][18];

int	main(int argc, char **argv)
{
	int		fd;
	int		len;
	int		pos[2];
	char	board[15][15];

	clear_board(&board);
	pos[0] = -1;
	pos[1] = 0;
	if (argc != 2)
		write(1, "usage: ./fillit source_file\n", 28);
	else if ((fd = open(argv[1], O_RDONLY)) > 0)
	{
		if ((len = get_tets(fd)))
			solve(&board, 0, pos, start_size(len));
		else
			write(1, "error\n", 6);
	}
	else
		write(1, "error\n", 6);
	return (0);
}
