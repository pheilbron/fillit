/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 14:45:12 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/07 16:25:25 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	empty_left_over(char **data, char *left_over, size_t *pos)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(left_over);
	i = 1;
	while (i < len && left_over[i] != '\n')
	{
		(*data)[*pos + (i - 1)] = left_over[i];
		i++;
	}
	*pos += (i - 1);
	if (i < len)
	{
		ft_memmove(left_over, left_over + i, len - i);
		ft_memset(left_over + (len - i), '\0', BUFF_SIZE - (len - i));
		return (0);
	}
	bzero(left_over, BUFF_SIZE);
	return (1);
}

int	read_buff(const int fd, char **data, size_t *pos)
{
	int			i;
	int			size;
	static char	left_over[BUFF_SIZE] = {'\0'};
	char		buff[BUFF_SIZE];

	i = 0;
	if (left_over[0])
		return (!empty_left_over(data, left_over, pos) ? -1 : 1);
	if ((size = read(fd, buff, BUFF_SIZE)) == -1)
		return (-2);
	while (i < size && buff[i] != '\n')
	{
		(*data)[(int)*pos + i] = buff[i];
		i++;
	}
	*pos += i;
	if (i < size)
	{
		ft_memcpy(left_over, buff + i, (size_t)(size - i));
		return (-1);
	}
	return (size);
}

int	get_next_line(const int fd, char **line)
{
	char	*temp;
	char	*holder;
	size_t	pos;
	int		size;
	size_t	new_size;

	pos = 0;
	new_size = BUFF_SIZE * sizeof(**line);
	temp = malloc(sizeof(*temp) * new_size);
	if (!line)
		return (-1);
	while ((size = read_buff(fd, &temp, &pos)) > 0)
	{
		if (pos + BUFF_SIZE > new_size)
		{
			holder = ft_memndup(temp, pos, new_size *= 2);
			free(temp);
			temp = holder;
		}
	}
	*line = ft_strndup(temp, pos);
	free(temp);
	if (size == -2)
		return (-1);
	return (pos > 0 || size == -1 ? 1 : 0);
}
