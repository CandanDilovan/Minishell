# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/25 15:27:08 by dilovancand       #+#    #+#              #
#    Updated: 2023/07/25 18:06:04 by dilovancand      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Minishell
SOURCES = 
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

INC_DIR : inc/
RL_INC : -I $(READLINE)/include
RL_LIB : -L $(READLINE)/lib -lreadline
LIBFT_LIB : libft/libft.a

all: ${NAME}

Minishell: ${OBJECTS}
	@make -C inc/libft
	$(CC) $(CFLAGS) ${OBJECTS} ${LIBFT_LIB} ${RL_LIB} -o Minishell 

%.o: %.c
	$(CC) -c $(CFLAGS) $(RL_INC) $(INC_DIR) $? 

clean:
	@make -C inc/libft clean
	rm -f ${OBJECTS}
	
fclean: clean
	@make -C inc/libft fclean
	rm -f ${NAME}

re: fclean all
