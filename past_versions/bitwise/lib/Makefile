# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/30 13:56:22 by pheilbro          #+#    #+#              #
#    Updated: 2019/08/01 22:58:25 by pheilbro         ###   ########.fr        #
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
				ft_memndup ft_wstrlen
CTYPE		=	ft_isspace ft_isblank ft_isalpha ft_isdigit ft_isalnum \
				ft_isascii ft_isprint
STDIO		=	ft_putchar ft_putstr ft_putendl ft_putnbr ft_putchar_fd \
				ft_putstr_fd ft_putendl_fd ft_putnbr_fd
STDLIB		=	ft_itoa ft_atoi ft_lltoa ft_ulltoa_base get_next_line \
				ft_memalloc
LIST		=	ft_lstnew ft_lstdelone ft_lstdel ft_lstadd ft_lstiter \
				ft_lstmap
VECTOR		=	ft_vect_add ft_vect_del ft_vect_resize ft_vect_new \
				ft_vect_init ft_vect_free ft_vect_get ft_vect_set
DSTRING		=	ft_dstr_add ft_dstr_del ft_dstr_free ft_dstr_new \
				ft_dstr_resize ft_dstr_init
MATH		=	ft_pow ft_max ft_min ft_int_sqrt
				
OBJ_DIR		=	obj
SRC_DIR		=	src

SRC			=	$(patsubst %, string/%, $(STRING)) \
				$(patsubst %, ctype/%, $(CTYPE)) \
				$(patsubst %, stdio/%, $(STDIO)) \
				$(patsubst %, stdlib/%, $(STDLIB)) \
				$(patsubst %, list/%, $(LIST)) \
				$(patsubst %, vector/%, $(VECTOR)) \
				$(patsubst %, dstring/%, $(DSTRING)) \
				$(patsubst %, math/%, $(MATH))
OBJS		=	$(patsubst %, $(OBJ_DIR)/%.o, $(SRC))

CC			=	gcc
AR			=	ar
INC			=	-I inc
CFLAGS		=	-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	@echo Creating libft.a...
	@$(AR) -rcs $@ $(OBJS)
	@ranlib $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo Compiling $<.
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@echo Removing object files...
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo Removing libft.a...
	@rm -f $(NAME)

re: fclean all
