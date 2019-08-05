/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 16:24:17 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/28 07:57:38 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*ret_i;
	t_list	*i;

	ret = malloc(sizeof(ret));
	i = lst;
	ret = (*f)(i);
	ret_i = ret;
	i = i->next;
	while (i)
	{
		ret_i->next = (*f)(i);
		i = i->next;
		ret_i = ret_i->next;
	}
	return (ret);
}
