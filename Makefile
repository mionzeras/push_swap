# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 13:58:26 by gcampos-          #+#    #+#              #
#    Updated: 2023/11/30 19:04:16 by gcampos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#SETUP
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I includes

#FILES
SRCS =	src/algorithm.c \
		src/init_stacks.c \
		src/push_swap.c \
		src/stack_utils.c \
		src/utils.c
OBJS = ${SRCS:.c=.o}

.c.o:
		@$ ${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}
		
all:	${NAME}

$(NAME): ${OBJS}
		@echo "Compiling ${NAME}..."
		${CC} ${CFLAGS} ${INCLUDE} ${OBJS} -o ${NAME}
		@echo "${NAME} compiled!"


clean:
		@$ rm -f ${OBJS}
		@echo "${NAME} cleaned!"

fclean: clean
		@$ rm -f ${NAME}
		@echo "${NAME} fcleaned!"

re: fclean all

.PHONY: all clean fclean re