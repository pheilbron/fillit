/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiblack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 21:41:46 by kiblack           #+#    #+#             */
/*   Updated: 2019/08/02 14:52:53 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "ft_math.h"
#include "ft_string.h"

int		check_piece(t_piece *tet, uint16_t *board)
{
	return (!(*(uint64_t *)(board + tet->pos.y) &
					(tet->bit_tet >> tet->pos.x)));
}

void	add_remove(t_piece *tet, uint16_t *board)
{
	*(uint64_t *)(board + tet->pos.y) ^= (tet->bit_tet >> tet->pos.x);
}

void	print_bit_board(uint16_t *board, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if ((board[i] >> (15 - j)) & (uint16_t)1)
				write(1, "#", 1);
			else
				write(1, ".", 1);
		}
		write (1, "\n", 1);
	}
	write(1, "\n", 1);
}

void	print_bit_tet(t_piece *tets)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (tets->bit_tet & (1UL << (i * 16 + j)))
				write(1, "A", 1);
			else
				write(1, ".", 1);
		}
		write(1, "\n", 1);
	}
	printf("(%d, %d), %llu\n", tets->pos.x, tets->pos.y, tets->bit_tet >> tets->pos.x);
	write(1, "\n", 1);
}

void	print_bit_board_int(uint16_t *board, t_piece *tet)
{
	printf("%llu\n", *(uint64_t *)(board + tet->pos.y));
	for (int i = 0; i < 16; i++)
		printf("%hu\n", board[i]);
}

int		solve(uint16_t *board, t_piece *tets, int size)
{
	if (!tets->char_tet[0])
		return (1);
	tets->pos.y = (tets->prev_same ? tets->prev_same->pos.y : 0);
	while (tets->pos.y <= size - tets->size.y)
	{
		tets->pos.x = (tets->prev_same &&
				tets->pos.y == tets->prev_same->pos.y ?
				tets->prev_same->pos.x : 0);
		while (tets->pos.x <= size - tets->size.x)
		{
			if (check_piece(tets, board))
			{
				add_remove(tets, board);
//				write(1, "tet:\n", 5);
//				print_bit_tet(tets);
//				write(1, "board:\n", 7);
//				print_bit_board(board, size+ + 5);
//				write(1, "board_int:\n", 11);
//				print_bit_board_int(board, tets);
//				write(1, "filled_board:\n", 14);
//				print_board(tets - (tets->id - 'A'), tets->id - 'A' + 1, size);
//				write(1, "\n\n", 2);
				if (solve(board, tets + 1, size))
					return (1);
				add_remove(tets, board);
			}
			tets->pos.x++;
		}
		tets->pos.y++;
	}
	tets->pos = (t_point){0, 0};
	return (0);
}

void	solve_puzzle(uint16_t *board, t_piece *tets, int len)
{
	int	size;

	size = 2;
	while (size * size < len * 4)
		size++;
	while (size < 17 && !solve(board, tets, size))
	{
		ft_bzero(board, sizeof(uint16_t) * 16);
		size++;
	}
	if (size < 17)
		print_board(tets, len, size);
}
