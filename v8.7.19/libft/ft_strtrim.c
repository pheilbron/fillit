/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:58:08 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/07 16:22:50 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ret;
	size_t	i;
	size_t	end;
	size_t	start;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	end = ft_strlen(s) - 1;
	while (s[i] && (s[end] == ' ' || s[end] == '\t' || s[end] == '\n'))
		end--;
	if (!(ret = malloc(sizeof(*ret) * (end - i + 2))))
		return (NULL);
	start = i;
	while (s[i] && i <= end)
	{
		ret[i - start] = s[i];
		i++;
	}
	ret[i - start] = '\0';
	return (ret);
}
