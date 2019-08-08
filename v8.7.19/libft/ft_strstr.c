/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 11:03:39 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/07 16:22:30 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t	h_len;
	size_t	n_len;

	i = 0;
	h_len = ft_strlen(haystack);
	n_len = ft_strlen(needle);
	if (needle == 0)
		return ((char *)haystack);
	while (h_len >= n_len && i <= h_len - n_len)
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
