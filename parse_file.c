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
#include "libft.h"

extern char	g_tets[27][18];

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

int		parse_file(int fd)
{
	int		tet_i;
	int		i;
	char	*line;

	tet_i = 0;
	i = 0;
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strlen(line) == 4 && i % 4 == 0 && i / 4 < 4)
		{
			ft_strncpy(g_tets[tet_i] + i, line, 4);
			i += 4;
		}
		else if (!ft_strcmp(line, "") && i / 4 == 4)
		{
			if (!check_tetramino(g_tets[tet_i++]))
				return (0);
			i = 0;
		}
		else
			return (0);
		free(line);
	}
	return (check_tetramino(g_tets[tet_i]) ? tet_i + 1 : 0);
}

void	trim_tet(int pos)
{
	int	height;
	int	width;

	height = 0;
	width = 0;
	while (!ft_strncmp(g_tets[pos], "....", 4))
		ft_lrotstr(g_tets[pos], 16, 4);
	while (height * 4 < 16 &&
			ft_strncmp(g_tets[pos] + (height * 4), "....", 4))
		height++;
	while (!ft_modstrncmp(g_tets[pos], "....", 4, 4))
		ft_lmodrotstr(g_tets[pos], 16, 4);
	while (width * 4 < 16 &&
			ft_modstrncmp(g_tets[pos] + width, "....", 4, 4))
		width++;
	g_tets[pos][16] = width;
	g_tets[pos][17] = height;
}

int		get_tets(int fd)
{
	int	i;
	int	len;

	i = 0;
	if ((len = parse_file(fd)) == 0)
		return (0);
	while (i < len)
		trim_tet(i++);
	g_tets[len][0] = -1;
	return (len);
}
