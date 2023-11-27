NAME = push_swap
CC = gcc -g -Wall -Wextra -Werror
SRC = init_stacks.c main.c utils.c check_input.c
OBJ = $(SRC:.c=.o)
INCLUDE = push_swap.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c $(INCLUDE)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
