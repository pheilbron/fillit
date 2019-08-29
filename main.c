/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 12:56:26 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/27 21:53:36 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	int			fd;
	int			len;
	t_piece		tets[27];
	uint16_t	board[16];

	ft_bzero(board, sizeof(uint16_t) * 16);
	if (argc != 2)
		ft_putstr("usage: ./fillit source_file\n");
	else if ((fd = open(argv[1], O_RDONLY)) > 0)
	{
		if ((len = parse_file(fd, &tets)))
		{
			tets[len].char_tet[0] = '\0';
			solve_puzzle(board, tets, len);
		}
		else
			ft_putstr("error\n");
		close(fd);
	}
	else
		ft_putstr("error\n");
	return (0);
}
