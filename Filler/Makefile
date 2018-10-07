# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jronald <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/26 10:29:50 by jronald           #+#    #+#              #
#    Updated: 2018/07/30 09:45:38 by jronald          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = jronald.filler

FLAGS = -Wall -Wextra -Werror -I

CC = clang -o

SRC= ./src/*.c

INC = ./includes/

all		:	$(NAME)

$(NAME)		:
			@make -C ./libft/
			@$(CC) $(NAME) $(SRC) $(FLAGS) $(INC) -L libft/ -lft
			@echo "jronald.filler compiled"

clean	:
			make clean -C ./libft/
			rm -rf $(NAME)

fclean	:
			make fclean -C ./libft/
			rm -rf $(NAME)

re		:	fclean all	
