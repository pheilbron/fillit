/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:01:50 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/28 08:34:25 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*ret;

	i = 0;
	ret = (char *)b;
	while (i < len)
		ret[i++] = c;
	return (ret);
}
