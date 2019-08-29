# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/30 13:56:22 by pheilbro          #+#    #+#              #
#    Updated: 2019/08/27 21:53:12 by pheilbro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fillit

CC			= gcc
INC			= -I. -I libft
LIB			= -Llibft -lft
CFLAGS		= -Wall -Werror -Wextra

SRC			= main parse_file solve print_board
OBJ			= $(patsubst %, %.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(CC) $(CFLAGS) $(INC) $(LIB) -o $@ $(OBJ)

%.o: %.c
	@echo Compiling $<.
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@make clean -C libft/
	@echo Removing object files...
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft/
	@echo Removing $(NAME)...
	@rm -f $(NAME)

re: fclean all
