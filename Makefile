# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmasetti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/19 12:33:00 by cmasetti          #+#    #+#              #
#    Updated: 2018/01/24 17:35:47 by sgarcia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAG = -Wall -Werror -Wextra

SRC = fillit.c tetriminos.c main.c functions.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make re -C Libft/
	gcc $(FLAG) -c $(SRC) -I fillit.h
	gcc $(OBJ) -o $(NAME) -L Libft/ -lft

clean:
	rm -f $(OBJ)
	@make clean -C Libft/

fclean: clean
	rm -f $(NAME)
	@make fclean -C Libft/

re: fclean all

.PHONY: all clean fclean re lib
