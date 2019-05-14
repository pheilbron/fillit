/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 15:57:06 by pheilbro          #+#    #+#             */
/*   Updated: 2019/05/13 16:08:43 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft.h"

int		start_size(int len);
int		get_tets(int fd, char (*tetraminos)[27][18]);
void	clear_board(void);
void	print_solution(int size);
void	print_tets(char (*tets)[27][18], int len);
int		solve(char tets[27][18], int t_i, int pos[2], int size);

#endif
