/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 13:17:17 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/28 08:34:06 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	*ft_memndup(const void *src, size_t len, size_t n)
{
	void	*dest;

	dest = malloc(n);
	ft_memcpy(dest, src, len);
	return (dest);
}
