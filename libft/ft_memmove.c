/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:09:23 by pheilbro          #+#    #+#             */
/*   Updated: 2019/05/01 14:28:40 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int				i;
	unsigned char	*dst_c;
	unsigned char	*src_c;

	i = (int)len - 1;
	dst_c = (unsigned char *)dst;
	src_c = (unsigned char *)src;
	if (dst > src && (src + len) > dst)
	{
		while (i >= 0)
		{
			dst_c[i] = src_c[i];
			i--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
