# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/30 13:56:22 by pheilbro          #+#    #+#              #
#    Updated: 2019/08/05 13:13:34 by pheilbro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fillit

CC			= gcc
INC			= -I inc -I lib/inc
LIB			= -L lib -lft
CFLAGS		= -Wall -Werror -Wextra
#DEBUG_FLAGS	= -g -fsanitize=address

OBJ_DIR		= obj
SRC_DIR		= src

SRC			= main parse_file solve print_board
OBJ			= $(patsubst %, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): libft $(OBJ) 
	@$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(INC) $(LIB) -o $@ $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo Compiling $<.
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

libft:
	@make -C lib/

clean:
	@echo Removing object files...
	@make clean -C lib/
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo Removing executable...
	@make fclean -C lib/
	@rm -f $(NAME)

re: fclean all
