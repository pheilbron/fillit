/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 16:10:12 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/28 08:48:48 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_math.h"

char	*ft_itoa(int n)
{
	char	*ret;
	int		sign;
	int		digit;
	int		i;
	long	nbr;

	sign = (n >= 0 ? 0 : 1);
	nbr = (sign == 0 ? n : (long)n * -1);
	digit = 0;
	i = 0;
	while (nbr / ft_pow(10, digit) >= 10)
		digit++;
	if (!(ret = (char *)malloc(sizeof(*ret) * (digit + 2 + sign))))
		return (NULL);
	if (sign)
		ret[i++] = '-';
	while (digit >= 0)
	{
		ret[i++] = (nbr / ft_pow(10, digit)) + '0';
		nbr -= (nbr / ft_pow(10, digit)) * ft_pow(10, digit);
		digit--;
	}
	ret[i] = '\0';
	return (ret);
}
