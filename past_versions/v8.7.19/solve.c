/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiblack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 21:41:46 by kiblack           #+#    #+#             */
/*   Updated: 2019/08/07 16:35:49 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		check_piece(t_piece *tet, uint16_t *board)
{
	return (!(*(uint64_t *)(board + tet->pos.y) &
				(tet->bit_tet >> tet->pos.x)));
}

void	add_remove(t_piece *tet, uint16_t *board)
{
	*(uint64_t *)(board + tet->pos.y) ^= (tet->bit_tet >> tet->pos.x);
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
