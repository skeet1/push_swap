# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/23 21:28:57 by mkarim            #+#    #+#              #
#    Updated: 2022/04/23 21:49:42 by mkarim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

HEADER = push_swap.h

SRC = push_swap.c ft_check_arg.c ft_split.c ft_strjoin.c ft_utils.c operations.c operations1.c operations2.c sort.c sort1.c sort2.c sort3.c sort4.c sort5.c sort6.c

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	@echo "Compilation of push_swap: \033[1;32mOK\033[m"

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -I. -c $<

clean :
	rm $(OBJ)
	@echo "\033[1;33m>> all objects files are deleted.\033[0m"

fclean :
	rm -rf $(NAME) $(OBJ)
	@echo "\033[0;31m>> $(NAME) is deleted.\033[0m"

re : fclean all
