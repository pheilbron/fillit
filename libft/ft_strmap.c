/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:49:17 by pheilbro          #+#    #+#             */
/*   Updated: 2019/05/01 09:08:56 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*ret;

	i = 0;
	if (!s)
		return (NULL);
	if (!(ret = malloc(sizeof(*ret) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i])
	{
		ret[i] = (*f)(s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
