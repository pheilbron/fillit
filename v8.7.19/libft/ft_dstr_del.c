/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstr_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 07:58:27 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/07 16:17:16 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dstr_del(t_dstring *s, size_t index)
{
	ft_memmove(s->buf + index, s->buf + index + 1, sizeof(*(s->buf)));
	s->pos--;
	if (s->pos < s->cap / 4)
		ft_dstr_resize(s, s->cap / 4);
}
