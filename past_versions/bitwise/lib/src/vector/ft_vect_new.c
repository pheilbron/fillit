/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 22:44:51 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/28 22:48:23 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector	*ft_vect_new(int capacity)
{
	t_vector *v;

	if ((v = malloc(sizeof(*v))))
	{
		v->pos = 0;
		v->cap = capacity;
		if (!(v->data = malloc(sizeof(size_t) * capacity)))
			return (NULL);
	}
	return (v);
}
