/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:05:26 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/07 16:19:10 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ret;
	unsigned char	*src_s;

	i = 0;
	ret = (unsigned char *)dst;
	src_s = (unsigned char *)src;
	while (i < n)
	{
		ret[i] = src_s[i];
		if (ret[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
