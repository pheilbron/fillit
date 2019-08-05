/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 11:09:06 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/28 08:42:07 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	h_len;
	size_t	n_len;

	i = 0;
	h_len = ft_strlen(haystack);
	n_len = ft_strlen(needle);
	if (n_len == 0)
		return ((char *)haystack);
	while ((int)i <= (int)len - (int)n_len && (int)i <= (int)h_len - (int)n_len)
	{
		j = 0;
		while (j < n_len)
		{
			if (haystack[j + i] != needle[j])
				break ;
			j++;
		}
		if (j == n_len)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
