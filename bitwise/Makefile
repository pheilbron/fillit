# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/30 13:56:22 by pheilbro          #+#    #+#              #
#    Updated: 2019/07/28 23:06:15 by pheilbro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fillit

CC			= gcc
INC			= -I inc -I lib/inc
LIB			= -L lib -lft
CFLAGS		= -Wall -Werror -Wextra
DEBUG_FLAGS	= -g -fsanitize=address

OBJ_DIR		= obj
SRC_DIR		= src

SRC			= main parse_file solve
OBJ			= $(patsubst %, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(INC) $(LIB) $@ $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo Compiling $<.
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

debug: $(OBJ)
	@$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(INC) $(LIB) $@ $(OBJ)

clean:
	@echo Removing object files...
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo Removing executable...
	@rm -f $(NAME)

re: fclean all
