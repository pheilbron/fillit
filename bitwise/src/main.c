/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 12:56:26 by pheilbro          #+#    #+#             */
/*   Updated: 2019/05/16 16:20:28 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "ft_stdio.h"

int	main(int argc, char **argv)
{
	int			fd;
	int			len;
	t_piece		*tets;
	uint16_t	board[16];

	clear_board(&board);
	if (argc != 2)
		ft_putstr("usage: ./fillit source_file\n");
	else if ((fd = open(argv[1], O_RDONLY)) > 0)
	{
		if ((len = parse_file(fd, &tets)))
			solve_puzzle(board, tets, len);
		else
			ft_putstr("error\n");
	}
	else
		ft_putstr("error\n");
	return (0);
}
