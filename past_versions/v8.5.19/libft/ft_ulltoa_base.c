/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:16:13 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/07 16:23:02 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_ullpow(int base, int exp)
{
	long long	ret;

	ret = 1;
	while (exp-- > 0)
		ret *= (unsigned long long)base;
	return (ret);
}

char				get_val(int n, int cap)
{
	char	*values;
	char	*c_values;

	values = "0123456789abcdef";
	c_values = "0123456789ABCDEF";
	if (cap)
		return (c_values[n]);
	return (values[n]);
}

char				*ft_ulltoa_base(unsigned long long n, int base, int cap)
{
	char	*ret;
	int		digit;
	int		i;

	digit = 0;
	i = 0;
	while (n / ft_ullpow(base, digit) >= (unsigned int)base)
		digit++;
	if (!(ret = (char *)malloc(sizeof(*ret) * (digit + 2))))
		return (NULL);
	while (digit >= 0)
	{
		ret[i++] = get_val(n / ft_ullpow(base, digit), cap);
		n -= (n / ft_ullpow(base, digit)) * ft_ullpow(base, digit);
		digit--;
	}
	ret[i] = '\0';
	return (ret);
}
