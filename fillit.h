/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 15:57:06 by pheilbro          #+#    #+#             */
/*   Updated: 2019/05/16 15:48:58 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft.h"

int		start_size(int len);
int		get_tets(int fd);
void	clear_board(char (*board)[15][15]);
void	print_solution(char board[15][15], int size);
void	print_tets(int len);
int		solve(char (*partial)[15][15], int t_i, int pos[2], int size);

#endif
