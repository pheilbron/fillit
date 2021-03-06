/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:02:48 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/07 16:19:26 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*ret;
	char	*src_c;

	i = 0;
	ret = (char *)dst;
	src_c = (char *)src;
	while (i < n)
	{
		ret[i] = src_c[i];
		i++;
	}
	return (dst);
}
