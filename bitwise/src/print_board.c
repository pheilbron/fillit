/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 21:58:36 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/02 12:32:45 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fillit.h"

void	empty_board(char (*board)[16][16], int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
			(*board)[i][j++] = '.';
		i++;
	}
}

void	make_char_board(char (*board)[16][16], t_piece *tets, int len)
{
	int	i;
	int	blocks_placed;
	int	j;

	i = 0;
	while (i < len)
	{
		blocks_placed = 0;
		j = 0;
		while (blocks_placed < 4 && j < 16)
		{
			if (tets[i].char_tet[j] == '#')
			{
				(*board)[tets[i].pos.y + j / 4][tets[i].pos.x + j % 4] = tets[i].id;
				blocks_placed++;
			}
			j++;
		}
		i++;
	}
}

void	print_board(t_piece *tets, int len, int size)
{
	char	char_board[16][16];
	int		y;

	y = 0;
	empty_board(&char_board, size);
	make_char_board(&char_board, tets, len);
	while (y < size)
	{
		write(1, char_board[y], size);
		write(1, "\n", 1);
		y++;
	}
}
