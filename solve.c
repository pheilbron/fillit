/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 10:22:51 by pheilbro          #+#    #+#             */
/*   Updated: 2019/05/13 16:28:14 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

extern char g_solution[12][12];

void	place_tet(char *t, int pos[2], int t_i)
{
	int	blocks_placed;
	int	i;

	blocks_placed = 0;
	i = 0;
	while (blocks_placed < 4 && i < 16)
	{
		if (t[i] == '#' && g_solution[pos[1] + i / 4][pos[0] + i % 4] == '.')
		{
			g_solution[pos[1] + i / 4][pos[0] + i % 4] = 'A' + t_i;
			blocks_placed++;
		}
		i++;
	}
}

int		*remove_tet(int t_i, int pos[2])
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
			if (g_solution[j][i] == 'A' + t_i)
			{
				if (pos[0] == -1 || pos[0] > i)
					pos[0] = i;
				if (pos[1] == -1 || pos[1] > j)
					pos[1] = j;
				g_solution[j][i] = '.';
			}
			j++;
		}
		i++;
	}
	return (pos);
}

int		test(char *t, int pos[2])
{
	int	blocks_placed;
	int	i;

	blocks_placed = 0;
	i = 0;
	while (blocks_placed < 4 && i < 16)
	{
		if (t[i] == '#' && g_solution[pos[1] + i / 4][pos[0] + i % 4] == '.')
			blocks_placed++;
		else if (t[i] == '#' && g_solution[pos[1] + i / 4][pos[0] + i % 4]
				!= '.')
			return (0);
		i++;
	}
	return (blocks_placed == 4);
}

int		*next_pos(char *tet, int pos[2], int size)
{
	while (pos[0] + tet[16] - 1 < size && pos[1] + tet[17] - 1 < size)
	{
		if (test(tet, pos))
			return (pos);
		pos[0]++;
		if (pos[0] + tet[16] > size)
		{
			pos[0] = 0;
			pos[1]++;
		}
	}
	pos[0] = -1;
	return (pos);
}

int		solve(char tets[27][18], int t_i, int pos[2], int size)
{
	int	origin[2];

	origin[0] = 0;
	origin[1] = 0;
	if (tets[t_i][0] == -1)
		return (size);
	if ((pos = next_pos(tets[t_i], pos, size))[0] != -1)
	{
		place_tet(tets[t_i], pos, t_i);
		return (solve(tets, t_i + 1, origin, size));
	}
	if (pos[0] == -1 && t_i > 0)
	{
		pos = remove_tet(t_i - 1, pos);
		pos[0]++;
		if (pos[0] + tets[t_i - 1][16] > size)
		{
			pos[0] = 0;
			pos[1]++;
		}
		return (solve(tets, t_i - 1, pos, size));
	}
	return (solve(tets, 0, origin, size + 1));
}
