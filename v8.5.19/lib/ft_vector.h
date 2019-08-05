/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 08:45:45 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/28 08:45:58 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include <stdlib.h>

typedef struct	s_vector
{
	void	**data;
	int		cap;
	int		pos;
}				t_vector;

t_vector		*ft_vect_init(t_vector *v, int capacity);
t_vector		*ft_vect_new(int capacity);
void			*ft_vect_add(t_vector *v, void *data);
t_vector		*ft_vect_resize(t_vector *v, int capacity);
void			*ft_vect_get(t_vector *v, int index);
void			ft_vect_set(t_vector *v, int index, void *item);
void			ft_vect_del(t_vector *v, int index);
void			ft_vect_free(t_vector *v);

#endif
