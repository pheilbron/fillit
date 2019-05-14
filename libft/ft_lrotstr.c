/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lrotstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 22:13:52 by pheilbro          #+#    #+#             */
/*   Updated: 2019/05/09 14:18:53 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lrotstr(char *str, size_t len, size_t offset)
{
	char	*temp;

	temp = ft_strndup(str, offset);
	ft_memmove(str, str + offset, len - offset);
	ft_memcpy(str + len - offset, temp, offset);
	free(temp);
}
