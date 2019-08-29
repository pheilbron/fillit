/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 16:00:34 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/07 16:22:24 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	size_t	i;
	int		count;

	i = 0;
	if (!*s)
		return (0);
	count = (s[i] != c ? 1 : 0);
	while (s[i + 1])
	{
		if (s[i] == c && s[i + 1] != c)
			count++;
		i++;
	}
	return (count);
}

static int	word_end(char const *s, char c, size_t start)
{
	size_t	i;

	i = start;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*next_word(char const *s, char c, size_t start, size_t end)
{
	size_t	i;
	size_t	head;
	char	*ret;

	i = start;
	while (s[i] && s[i] == c)
		i++;
	head = i;
	if (!(ret = malloc(sizeof(*ret) * (end - head + 1))))
		return (NULL);
	i = 0;
	while (i < end - head)
	{
		ret[i] = s[head + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		words;
	char	**ret;

	i = 0;
	j = 0;
	if (!s || !c)
		return (NULL);
	words = word_count(s, c);
	if (!(ret = malloc(sizeof(*ret) * (words + 1))))
		return (NULL);
	while (i < words)
	{
		if (!(ret[i] = next_word(s, c, j, word_end(s, c, j))))
			return (NULL);
		i++;
		j = word_end(s, c, j);
	}
	ret[i] = 0;
	return (ret);
}
