# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/30 13:56:22 by pheilbro          #+#    #+#              #
#    Updated: 2019/08/05 15:42:17 by pheilbro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fillit

CC			= gcc
INC			= -I . -I lib
LIB			= -L lib -lft
CFLAGS		= -Wall -Werror -Wextra

SRC			= main parse_file solve print_board
OBJ			= $(patsubst %, %.o, $(SRC))

all: $(NAME)

$(NAME): libft $(OBJ) 
	@$(CC) $(CFLAGS) $(INC) $(LIB) -o $@ $(OBJ)

%.o: %.c
	@echo Compiling $<.
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

libft:
	@make -C lib/

clean:
	@make clean -C lib/
	@echo Removing object files...
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C lib/
	@echo Removing $(NAME)...
	@rm -f $(NAME)

re: fclean all
