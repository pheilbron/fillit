/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect_resize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 22:57:04 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/28 22:57:09 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector	*ft_vect_resize(t_vector *v, int capacity)
{
	void	**data;
	int		i;

	if (capacity == 0)
		capacity = 1;
	if ((data = malloc(sizeof(size_t) * capacity)))
	{
		i = -1;
		while (++i < v->pos)
			data[i] = v->data[i];
		free(v->data);
		v->data = data;
		v->cap = capacity;
		return (v);
	}
	return (NULL);
}
