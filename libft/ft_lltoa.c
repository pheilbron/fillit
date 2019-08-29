/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:16:24 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/07 16:18:20 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_llpow(int base, int exp)
{
	long long	ret;

	ret = 1;
	while (exp-- > 0)
		ret *= (long long)base;
	return (ret);
}

char		*ft_lltoa(long long n)
{
	char	*ret;
	int		sign;
	int		digit;
	int		i;

	sign = (n >= 0 ? 0 : 1);
	if (n == LLONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	n *= (sign ? -1 : 1);
	digit = 0;
	i = 0;
	while (n / ft_llpow(10, digit) >= 10)
		digit++;
	if (!(ret = (char *)malloc(sizeof(*ret) * (digit + 2 + sign))))
		return (NULL);
	if (sign)
		ret[i++] = '-';
	while (digit >= 0)
	{
		ret[i++] = (n / ft_llpow(10, digit)) + '0';
		n -= (n / ft_llpow(10, digit)) * ft_llpow(10, digit);
		digit--;
	}
	ret[i] = '\0';
	return (ret);
}
