# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/30 13:56:22 by pheilbro          #+#    #+#              #
#    Updated: 2019/05/09 14:30:54 by pheilbro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

PART1 = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c \
		ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c \
		ft_strcat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
		ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
		ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
		ft_tolower.c ft_memccpy.c ft_strncat.c

PART2 = ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
		ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
		ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
		ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS =	ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
		ft_lstmap.c

ADDN =	ft_isblank.c ft_pow.c ft_stpncpy.c ft_strndup.c ft_isspace.c \
		ft_stpcpy.c ft_strlcpy.c ft_memndup.c get_next_line.c \
		ft_lrotstr.c ft_modstrncmp.c ft_lmodrotstr.c

FILES =	$(PART1) $(PART2) $(BONUS) $(ADDN)

OBJ =	$(FILES:.c=.o)

CC =	gcc
AR =	ar
INC =	-I includes/
FLAGS =	-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) rcs $(NAME) $(OBJ)

$(OBJ): $(FILES)
	$(CC) $(INC) $(FLAGS) -c $(FILES)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
