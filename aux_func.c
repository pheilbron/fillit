/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_fun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 22:05:27 by pheilbro          #+#    #+#             */
/*   Updated: 2019/05/16 19:45:30 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

int		print_solution(char board[15][15], int size)
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
	return (size);
}

int		start_size(int len)
{
	int	ret;

	ret = 2;
	while (ret * ret < len * 4)
		ret++;
	return (ret);
}
