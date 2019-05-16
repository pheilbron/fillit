/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_fun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 22:05:27 by pheilbro          #+#    #+#             */
/*   Updated: 2019/05/16 15:48:27 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

extern char	g_tets[27][18];

void	clear_board(char (*board)[15][15])
{
	int	i;
	int	j;

	i = 0;
	while (i < 15)
	{
		j = 0;
		while (j < 15)
			(*board)[i][j++] = '.';
		i++;
	}
}

void	print_solution(char board[15][15], int size)
{
	int	i;

	i = 0;
	if (size < 0)
		size *= -1;
	while (i < size)
	{
		write(1, board[i], size);
		write(1, "\n", 1);
		i++;
	}
}

void	print_tets(int len)
{
	int	i;
	int	tet_i;

	i = 0;
	tet_i = 0;
	while (tet_i < len)
	{
		printf("%cx%c\n", g_tets[tet_i][16] + '0', g_tets[tet_i][17] + '0');
		while (i < 16)
		{
			write(1, g_tets[tet_i] + i, 4);
			write(1, "\n", 1);
			i += 4;
		}
		if (tet_i + 1 != len)
			write(1, "\n", 1);
		i = 0;
		tet_i++;
	}
}

int		start_size(int len)
{
	int	ret;

	ret = 2;
	while (ret * ret < len * 4)
		ret++;
	return (ret);
}
