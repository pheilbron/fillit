#include "fillit.h"

int		check_piece(t_piece *tet, uint16_t *board)
{
	return (!(*(uint64_t *)(board + tet->pos.y) &
					(tet->bit_tet >> tet->pos.x)));
}

void	add_remove(t_piece *tet, uint16_t *board)
{
	*(uint64_t *)(map + tet->pos.y) ^= tet->value >> tet->pos.x;
}

int		solve(uint16_t *board, t_piece *tets, int len)
{
	int	x;
	int	y;

	if (!*tets)
		return (1);
	y = 0;
	while (y < len - tets->size.y)
	{
		x = 0;
		while (x < len - tets->size.x)
		{
			if (check_piece(tets, board))
			{
				add_remove(tets, board);
				if (solve(board, tets + 1, len))
					return (1);
				add_remove(tets, board);
			}
			x++;

void	solve_board(uint16_t *board, t_piece *tets, int len)
{
	int	size;

	size = ft_int_sqrt(len * 4);
	while (size < 17 && !solve(board, tets, len, size))
	{
		ft_bzero(board, sizeof(uint16_t) * 16);
		size++;
	}
	if (size < 17)
		print_board(board, tets, len, size);
}
