/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_fun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 22:05:27 by pheilbro          #+#    #+#             */
/*   Updated: 2019/05/13 16:26:49 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

extern char g_solution[12][12];

void	clear_board(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < 12)
	{
		j = 0;
		while (j < 12)
			g_solution[i][j++] = '.';
		i++;
	}
}

void	print_solution(int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		write(1, g_solution[i], size);
		write(1, "\n", 1);
		i++;
	}
}

void	print_tets(char (*tets)[27][18], int len)
{
	int	i;
	int	tet_i;

	i = 0;
	tet_i = 0;
	while (tet_i < len)
	{
		printf("%cx%c\n", (*tets)[tet_i][16] + '0', (*tets)[tet_i][17] + '0');
		while (i < 16)
		{
			write(1, (*tets)[tet_i] + i, 4);
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
