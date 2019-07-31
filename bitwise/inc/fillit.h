#ifndef FILLIT_H
# define FILLIT_H

# include <stdint.h>

typedef struct	s_point
{
	uint8_t	x;
	uint8_t	y;
}				t_point;

typedef struct	s_piece
{
	char			char_tet[16];
	uint16_t		bit_tet;
	t_point			size;
	t_point			pos;
	t_point			board_pos;
	char			id;
	struct s_piece	*prev_tet;
}				t_piece;

int				parse_file(int ft, t_piece **tets);

#endif
