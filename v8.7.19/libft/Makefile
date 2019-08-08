# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/30 13:56:22 by pheilbro          #+#    #+#              #
#    Updated: 2019/08/07 16:37:16 by pheilbro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

STRING		=	ft_strlen ft_strdup ft_strcpy ft_strncpy ft_strcat ft_strlcat \
				ft_strchr ft_strrchr ft_strstr ft_strnstr ft_strcmp ft_strncmp \
				ft_toupper ft_tolower ft_memccpy ft_strncat ft_strnew \
				ft_strdel ft_strclr ft_striter ft_striteri ft_strmap \
				ft_strmapi ft_strequ ft_strnequ ft_strsub ft_strjoin \
				ft_strtrim ft_strsplit ft_stpncpy ft_strndup ft_stpcpy \
				ft_strlcpy ft_lrotstr ft_modstrncmp ft_lmodrotstr ft_memset \
				ft_bzero ft_memcpy ft_memmove ft_memchr ft_memcmp ft_memdel \
				ft_memndup
CTYPE		=	ft_isspace ft_isblank ft_isalpha ft_isdigit ft_isalnum \
				ft_isascii ft_isprint
STDIO		=	ft_putchar ft_putstr ft_putendl ft_putnbr ft_putchar_fd \
				ft_putstr_fd ft_putendl_fd ft_putnbr_fd
STDLIB		=	ft_itoa ft_atoi ft_lltoa ft_ulltoa_base get_next_line \
				ft_memalloc
LIST		=	ft_lstnew ft_lstdelone ft_lstdel ft_lstadd ft_lstiter \
				ft_lstmap
DSTRING		=	ft_dstr_add ft_dstr_del ft_dstr_free ft_dstr_new \
				ft_dstr_resize ft_dstr_init
MATH		=	ft_pow ft_max ft_min ft_int_sqrt
				
SRC			=	$(STRING) $(CTYPE) $(STDIO) $(STDLIB) $(LIST) $(DSTRING) $(MATH)
OBJ			= 	$(patsubst %, %.o, $(SRC))

CC			=	gcc
AR			=	ar
INC			=	-I . 
CFLAGS		=	-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@echo Creating libft.a...
	@$(AR) -rcs $@ $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@echo Compiling $<.
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@echo Removing object files...
	@rm -f $(OBJ)

fclean: clean
	@echo Removing libft.a...
	@rm -f $(NAME)

re: fclean all
