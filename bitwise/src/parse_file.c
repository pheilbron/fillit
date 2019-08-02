/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 14:34:18 by pheilbro          #+#    #+#             */
/*   Updated: 2019/05/14 14:42:37 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "ft_string.h"
#include "ft_stdlib.h"

int		check_sides(char *tetramino, int pos)
{
	int	touch;

	touch = 0;
	if (pos > 3)
		if (tetramino[pos - 4] == '#')
			touch++;
	if (pos < 12)
		if (tetramino[pos + 4] == '#')
			touch++;
	if (pos % 4 > 0)
		if (tetramino[pos - 1] == '#')
			touch++;
	if (pos % 4 < 3)
		if (tetramino[pos + 1] == '#')
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

void	set_tet_points(t_piece **tets, int pos)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if ((*tets)[pos].char_tet[i] == '#')
		{
			if (i / 4 < (*tets)[pos].pos.x)
				(*tets)[pos].pos.x = i / 4;
			if (i % 4 < (*tets)[pos].pos.y)
				(*tets)[pos].pos.y = i % 4;
			if (i / 4 > (*tets)[pos].size.x)
				(*tets)[pos].size.x = i / 4;
			if (i % 4 > (*tets)[pos].size.y)
				(*tets)[pos].size.y = i % 4;
		}
		i++;
	}
	(*tets)[pos].size.x -= (*tets)[pos].pos.x;
	(*tets)[pos].size.y -= (*tets)[pos].pos.y;
}

int		fill_in_tets(t_piece **tets, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		(*tets)[i].pos = (t_point){3, 3};
		(*tets)[i].size = (t_point){0, 0};
		set_tet_points(tets, i);
		(*tets)[i].board_pos = {0, 0};
		(*tets)[i]->prev_tet = (i > 0 ? (*tets)[i - 1] : NULL);
		(*tets)[i].id = 'A' + i;
		(*tets)[i].bit_tet = 0;
		j = 0;
		while (j < 16)
		{
			if ((*tets)[i].char_tet[j] == '#')
				tetris.value |= (1UL << (63 - (((j / 4) * 16) + (j % 4))));
			j++;
		}
		i++;
	}
}


int		parse_file(int fd, t_piece **tets)
{
	int		tet_i;
	int		i;
	char	*line;

	tet_i = 0;
	i = 0;
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		ft_strncpy((*tets)[tet_i].char_tet + i, line, 4);
		if (ft_strlen(line) == 4 && i % 4 == 0 && i / 4 < 4)
			i += 4;
		else if (!ft_strcmp(line, "") && i / 4 == 4)
		{
			if (!check_tetramino((*tets)[tet_i++].char_tet))
				return (0);
			i = 0;
		}
		else
			return (0);
		free(line);
	}
	if (check_tetramino((*tets)[tet_i].char_tet))
		return (fill_in_tets(tets, tet_i));
	return (0);
}
