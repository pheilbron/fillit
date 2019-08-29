/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstr_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 07:58:02 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/07 16:17:12 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dstr_add(t_dstring *s, char *new_data, size_t len)
{
	if (s->cap < s->pos + len)
		ft_dstr_resize(s, s->cap * 2 + (s->cap >= len ? 0 : len));
	ft_memcpy(s->buf + s->pos, new_data, len);
	s->buf[s->pos + len] = '\0';
	s->pos += len;
}
