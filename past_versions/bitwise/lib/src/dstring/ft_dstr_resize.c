/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstr_resize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:57:29 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/30 14:57:32 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dstring.h"

t_dstring	*ft_dstr_resize(t_dstring *s, size_t len)
{
	t_dstring	*temp;

	temp = ft_dstr_new(s->buf,
			(s->pos < len ? s->pos : len),
			(s->pos < len ? s->pos : len));
	ft_dstr_free(s);
	s = ft_dstr_new(temp->buf, temp->pos, len);
	ft_dstr_free(temp);
	return (s);
}
