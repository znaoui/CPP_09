# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zaktarus <znaoui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 22:16:31 by zaktarus          #+#    #+#              #
#    Updated: 2022/11/22 22:20:29 by zaktarus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############### SETUP ###############

NAME = RPN

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = $(addprefix , main.cpp RPN.cpp) \

OBJS = $(SRCS:.cpp=.o)

############### COMMANDS ###############

all:
	@make --no-print-directory ${NAME}

.c.o:
	c++ ${CFLAGS} -c $< -o ${<:.c=.o} -I RPN.hpp

${NAME}: ${OBJS} Makefile
	c++ ${CFLAGS} -o ${NAME} ${OBJS}
	echo "$(WHITE)Compilation in progress..$(DEFAULT)"
	sleep 1
	echo "$(GREEN)The program ${NAME} is ready!$(DEFAULT)"

help: 
	echo "$(WHITE)Commands available: all, clean, fclean, re$(DEFAULT)"

clean:
	rm -rf ${OBJS}
	echo "$(YELLOW)All object files have been deleted$(DEFAULT)"

fclean: clean
	rm -rf ${NAME}
	echo "$(RED)The program ${NAME} has been deleted$(DEFAULT)"

re: fclean
	make --no-print-directory all

.PHONY: all help clean fclean re

.SILENT:

################ COLORS ###############

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
WHITE = \033[1;37m
