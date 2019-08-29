/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 16:16:05 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/28 08:06:34 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"

void	ft_putnbr(int n)
{
	long	temp;

	temp = n;
	if (n < 0)
	{
		ft_putchar('-');
		temp = (long)n * -1;
	}
	if (temp >= 10)
		ft_putnbr(temp / 10);
	ft_putchar((temp % 10) + '0');
}
