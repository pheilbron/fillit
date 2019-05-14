/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:40:16 by pheilbro          #+#    #+#             */
/*   Updated: 2019/04/29 18:40:27 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	long	temp;

	temp = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		temp = (long)n * -1;
	}
	if (temp >= 10)
		ft_putnbr_fd(temp / 10, fd);
	ft_putchar_fd((temp % 10) + '0', fd);
}
