/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 23:03:17 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/02 15:02:56 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdint.h>
# include <fcntl.h>

typedef struct	s_point
{
	uint8_t	x;
	uint8_t	y;
}				t_point;

typedef struct	s_piece
{
	char			char_tet[16];
	uint64_t		bit_tet;
	t_point			size;
	t_point			pos;
	struct s_piece	*prev_same;
}				t_piece;

int				parse_file(int ft, t_piece (*tets)[27]);
void			solve_puzzle(uint16_t *board, t_piece *tets, int len);
void			print_board(t_piece *tets, int len, int size);

#endif
