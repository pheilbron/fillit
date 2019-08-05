/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 16:23:42 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/28 07:57:16 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*i;

	i = lst;
	while (i)
	{
		(*f)(i);
		i = i->next;
	}
}