#include "fillit.h"

int		check_piece(t_piece *tet, uint16_t *board)
{
	return (!(*(uint64_t *)(board + tet->pos.y &
					(tet->bit_tet >> tet->pos.x))));
}

void	add_remove(t_piece *tet, uint16_t *board)
{
	*(uint64_t *)(map + tet->pos.y ^= tet->value >> tet->pos.x);
}

int		solve(uint16_t *board, t_piece *tets, int len)
{
	if (tets->

void	solve_board(uint16_t *board, t_piece *tets, int len)
{
	int	size;

	size = ft_int_sqrt(len * 4);
	while (!solve(board, tets, len, size))
		size++;
	print_board(board, tets, len, size);
}
