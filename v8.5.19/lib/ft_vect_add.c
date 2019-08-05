/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 23:09:43 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/28 23:09:45 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	*ft_vect_add(t_vector *v, void *data)
{
	if (v->cap == v->pos && !ft_vect_resize(v, v->cap * 2))
		return (NULL);
	v->data[v->pos] = data;
	v->pos++;
	return (v->data[v->pos - 1]);
}
