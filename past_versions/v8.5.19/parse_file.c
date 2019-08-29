/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 14:34:18 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/07 22:47:05 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		check_sides(char *tetramino, int pos)
{
	int	touch;

	touch = 0;
	if (pos > 3 && tetramino[pos - 4] == '#')
		touch++;
	if (pos < 12 && tetramino[pos + 4] == '#')
		touch++;
	if (pos % 4 > 0 && tetramino[pos - 1] == '#')
		touch++;
	if (pos % 4 < 3 && tetramino[pos + 1] == '#')
		touch++;
	return (touch);
}

int		check_tetramino(char *tetramino)
{
	size_t	i;
	int		block_count;
	int		side_count;

	i = 0;
	block_count = 0;
	side_count = 0;
	while (i < 16)
	{
		if (tetramino[i] == '#')
		{
			side_count += check_sides(tetramino, i);
			block_count++;
		}
		else if (tetramino[i] != '.')
			return (0);
		i++;
	}
	if (block_count != 4 || !(side_count == 6 || side_count == 8))
		return (0);
	return (1);
}

void	trim_tet(t_piece *tet)
{
	int	height;
	int	width;

	height = 0;
	width = 0;
	while (!ft_strncmp(tet->char_tet, "....", 4))
		ft_lrotstr(tet->char_tet, 16, 4);
	while (height * 4 < 16 &&
			ft_strncmp(tet->char_tet + (height * 4), "....", 4))
		height++;
	while (!ft_modstrncmp(tet->char_tet, "....", 4, 4))
		ft_lmodrotstr(tet->char_tet, 16, 4);
	while (width * 4 < 16 &&
			ft_modstrncmp(tet->char_tet + width, "....", 4, 4))
		width++;
	tet->size.x = width;
	tet->size.y = height;
	tet->pos = (t_point){0, 0};
	tet->bit_tet = 0;
}

int		fill_in_tets(t_piece (*ts)[27], int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		if (check_tetramino((*ts)[i].char_tet) == 0)
			return (0);
		trim_tet((*ts) + i);
		j = 0;
		while (j < 16)
		{
			if ((*ts)[i].char_tet[j] == '#')
				(*ts)[i].bit_tet |= (1UL << (((j / 4) * 16) + (15 - (j % 4))));
			j++;
		}
		j = i - 1;
		(*ts)[i].prev_same = NULL;
		while (j >= 0 && (*ts)[j].bit_tet != (*ts)[i].bit_tet)
			j--;
		if (i >= 0 && (*ts)[j].bit_tet == (*ts)[i].bit_tet)
			(*ts)[i].prev_same = (*ts) + j;
		i++;
	}
	return (len);
}

int		parse_file(int fd, t_piece (*tets)[27])
{
	int		tet_i;
	int		i;
	char	*line;

	tet_i = 0;
	i = 0;
	line = NULL;
	while (tet_i < 26 && get_next_line(fd, &line) > 0)
	{
		ft_strncpy((*tets)[tet_i].char_tet + i, line, 4);
		if (ft_strlen(line) == 4 && i % 4 == 0 && i / 4 < 4)
			i += 4;
		else if (!ft_strcmp(line, "") && i / 4 == 4)
		{
			i = 0;
			tet_i++;
		}
		else
			return (0);
		free(line);
	}
	if (tet_i < 26)
		free(line);
	return (tet_i < 26 ? fill_in_tets(tets, tet_i + 1) : 0);
}
