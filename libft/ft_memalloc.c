/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:02:10 by pheilbro          #+#    #+#             */
/*   Updated: 2019/05/01 12:35:33 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*ret;

	i = 0;
	if (!(ret = malloc(sizeof(*ret) * size)))
		return (NULL);
	while (i < size)
		ret[i++] = 0;
	return ((void *)ret);
}
