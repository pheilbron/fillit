/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstr_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 07:58:58 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/07 16:17:23 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dstring	*ft_dstr_init(t_dstring *s)
{
	if (!(s = malloc(sizeof(*s))))
		return (NULL);
	if ((s->buf = ft_memalloc(sizeof(*(s->buf)) * DSTRING_INIT_SIZE)))
	{
		s->buf[0] = '\0';
		s->cap = DSTRING_INIT_SIZE;
		s->pos = 0;
		return (s);
	}
	return (NULL);
}
