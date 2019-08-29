/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 08:13:48 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/28 08:25:24 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

# define BUFF_SIZE 32

int		ft_atoi(const char *str);
int		ft_atoi_end(const char *str, int *pos);
char	*ft_itoa(int n);
int		get_next_line(const int fd, char **line);
char	*ft_lltoa(long long n);
void	*ft_memalloc(size_t size);
char	*ft_ulltoa_base(unsigned long long n, int base, int cap);

#endif
