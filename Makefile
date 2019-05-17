NAME		= fillit

SRC			= parse_file.c aux_func.c solve.c
MAIN		= main.c

OBJ			= $(SRC:.c=.o)
MAIN_OBJ	= $(MAIN:.c=.o)

CC			= gcc
INC			= -I . -I libft/includes
LIB			= -Llibft/ -lft
FLAGS		= -Wall -Werror -Wextra
DEBUG_FLAGS	= -g -fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(FLAGS) $(INC) $(LIB) -o $(NAME) $(OBJ) $(MAIN_OBJ)

$(OBJ): $(SRC) $(TEST_SRC)
	$(CC) $(FLAGS) $(INC) -c $(SRC) $(MAIN)

debug:
	make -C libft/
	$(CC) $(FLAGS) $(DEBUG_FLAGS) $(INC) $(LIB) $(SRC) $(MAIN)

clean:
	rm -f $(OBJ) $(MAIN_OBJ)
	make clean -C libft/

clean_debug:
	rm -f a.out
	rm -rf a.out.dSYM 

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all
