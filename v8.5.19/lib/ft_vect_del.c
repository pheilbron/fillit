/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 22:49:57 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/28 22:53:45 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_string.h"

void	ft_vect_del(t_vector *v, int index)
{
	ft_memmove(v->data + index,
			v->data + index + 1,
			(v->pos - index - 1) * sizeof(size_t));
	v->pos--;
	if (v->pos <= v->cap / 4)
		ft_vect_resize(v, v->cap / 4);
}
