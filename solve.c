/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 10:22:51 by pheilbro          #+#    #+#             */
/*   Updated: 2019/05/16 16:04:59 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

extern char	g_tets[27][18];

void	place_tet(char (*partial)[15][15], char *t, int pos[2], int t_i)
{
	int	blocks_placed;
	int	i;

	blocks_placed = 0;
	i = 0;
	while (blocks_placed < 4 && i < 16)
	{
		if (t[i] == '#' && (*partial)[pos[1] + i / 4][pos[0] + i % 4] == '.')
		{
			(*partial)[pos[1] + i / 4][pos[0] + i % 4] = 'A' + t_i;
			blocks_placed++;
		}
		i++;
	}
}

int		*remove_tet(char (*partial)[15][15], int t_i, int pos[2])
{
	int	i;
	int	j;

	i = 0;
	pos[0] = -1;
	pos[1] = -1;
	while (i < 12)
	{
		j = 0;
		while (j < 12)
		{
			if ((*partial)[j][i] == 'A' + t_i)
			{
				if (pos[0] == -1 || pos[0] > i)
					pos[0] = i;
				if (pos[1] == -1 || pos[1] > j)
					pos[1] = j;
				(*partial)[j][i] = '.';
			}
			j++;
		}
		i++;
	}
	return (pos);
}

int		test(char (*partial)[15][15], char *t, int pos[2])
{
	int	blocks_placed;
	int	i;

	blocks_placed = 0;
	i = 0;
	while (blocks_placed < 4 && i < 16)
	{
		if (t[i] == '#' && (*partial)[pos[1] + i / 4][pos[0] + i % 4] == '.')
			blocks_placed++;
		else if (t[i] == '#' && (*partial)[pos[1] + i / 4][pos[0] + i % 4]
				!= '.')
			return (0);
		i++;
	}
	return (blocks_placed == 4);
}

int		*next_pos(char (*partial)[15][15], char *tet, int pos[2], int size)
{
	while (pos[0] + tet[16] - 1 < size && pos[1] + tet[17] - 1 < size)
	{
		pos[0]++;
		if (pos[0] + tet[16] > size)
		{
			pos[0] = 0;
			pos[1]++;
			if (pos[1] + tet[17] > size)
			{
				pos[1] = -1;
				return (pos);
			}
		}
		if (test(partial, tet, pos))
			return (pos);
	}
	pos[1] = -1;
	return (pos);
}

int		solve(char (*partial)[15][15], int t_i, int pos[2], int size)
{
	int	origin[2];
	int	done;

	origin[0] = -1;
	origin[1] = 0;
	done = size;
	if (g_tets[t_i][0] == -1)
	{
		print_solution(*partial, size);
		return (size * -1);
	}
	pos = next_pos(partial, g_tets[t_i], pos, size);
	while (done >= 0 && pos[1] != -1)
	{
		place_tet(partial, g_tets[t_i], pos, t_i);
		done = solve(partial, t_i + 1, origin, size);
		pos = remove_tet(partial, t_i, pos);
		pos = next_pos(partial, g_tets[t_i], pos, size);
	}
	if (done >= 0 && t_i == 0)
	{
		clear_board(partial);
		done = (solve(partial, 0, origin, size + 1));
	}
	return (done < 0 ? done : 0);
}
