# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 13:58:26 by gcampos-          #+#    #+#              #
#    Updated: 2023/11/14 17:02:38 by gcampos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#SETUP
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
INCLUDE = -I includes

#FILES
SRCS = src/main.c src/utils.c src/check_input.c
OBJS = ${SRCS:.c=.o}


.c.o:
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

all:	${NAME}

$(NAME): ${OBJS}
		@echo "Compiling ${NAME}..."
		${CC} ${CFLAGS} ${INCLUDE} ${OBJS} -o ${NAME}
		@echo "${NAME} compiled!"


clean:
		@${RM} ${OBJS}
		@echo "${NAME} cleaned!"

fclean: clean
		@${RM} ${NAME}
		@echo "${NAME} fcleaned!"

re: fclean all

.PHONY: all clean fclean re