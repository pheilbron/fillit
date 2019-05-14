/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modstrncmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 13:44:25 by pheilbro          #+#    #+#             */
/*   Updated: 2019/05/09 14:21:05 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_modstrncmp(char *s1, char *s2, size_t n, size_t mod)
{
	if (n == 0)
		return (0);
	while (*s2 && *s1 && --n)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1 += mod;
		s2++;
	}
	if (*s1 && *s2)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	return (-1);
}
