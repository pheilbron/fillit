/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 11:16:19 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/28 08:16:48 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_ctype.h"

int	ft_atoi_end(const char *str, int *pos)
{
	size_t	i;
	int		sign;
	long	ret;

	i = 0;
	sign = 1;
	ret = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = (str[i++] == '-' ? -1 : 1);
	while (ft_isdigit(str[i]))
		ret = (ret * 10) + (str[i++] - '0');
	(*pos) += i;
	return ((int)(ret * sign));
}
