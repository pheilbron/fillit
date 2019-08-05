/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 22:44:41 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/30 17:41:57 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector	*ft_vect_init(t_vector *v, int capacity)
{
	v->pos = 0;
	v->cap = capacity;
	if (!(v->data = malloc(sizeof(size_t) * capacity)))
		return (NULL);
	return (v);
}
