/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 16:15:36 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/28 08:06:06 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"

void	ft_putendl(char const *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
	write(1, "\n", 1);
}