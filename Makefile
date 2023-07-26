# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/25 15:27:08 by dilovancand       #+#    #+#              #
#    Updated: 2023/07/26 22:32:46 by dilovancand      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Minishell
SOURCES = src/minishell.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

LIBFT_LIB = inc/libft/libft.a
INC_DIR = inc/
READLINE = $(shell brew --prefix readline)
RL_INC = -I $(READLINE)/include
RL_LIB = -L $(READLINE)/lib -lreadline

all: ${NAME}

src/%.o: src/%.c
	$(CC) -c $(CFLAGS) $(RL_INC) -I $(INC_DIR) $< -o $@

${NAME}: ${OBJECTS}
	make -C inc/libft
	$(CC) $(CFLAGS) ${OBJECTS} ${LIBFT_LIB} ${RL_LIB} -o ${NAME}

clean:
	make -C inc/libft clean
	rm -f ${OBJECTS}
	
fclean: clean
	make -C inc/libft fclean
	rm -f ${NAME}

re: fclean all
