/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 12:56:26 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/02 14:52:53 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "ft_stdio.h"
#include "ft_string.h"

#include <stdio.h>
void	print_parse_info(t_piece tets[27], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("TET: %s\nBIT_TET: %llu\nSize: (%d, %d)\nPos: (%d, %d)\nID: %c\n",
				tets[i].char_tet, tets[i].bit_tet, tets[i].size.x, tets[i].size.y,
				tets[i].pos.x, tets[i].pos.y, tets[i].id);
		printf("PREV_TET: %p ", tets[i].prev_same);
		if (tets[i].prev_same)
			printf("(id) %c", tets[i].prev_same->id);
		printf("\n\n");
	}
}

int	main(int argc, char **argv)
{
	int			fd;
	int			len;
	t_piece		tets[27];
	uint16_t	board[16];

	ft_bzero(board, sizeof(uint16_t) * 16);
	if (argc != 2)
		ft_putstr("usage: ./fillit source_file\n");
	else if ((fd = open(argv[1], O_RDONLY)) > 0)
	{
		if ((len = parse_file(fd, &tets)))
		{
			tets[len].char_tet[0] = '\0';
//			print_parse_info(tets, len);
			solve_puzzle(board, tets, len);
//			print_parse_info(tets, len);
		}
		else
			ft_putstr("error\n");
	}
	else
		ft_putstr("error\n");
	return (0);
}
