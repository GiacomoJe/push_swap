# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgiacomo <jefersongiacomo@gmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 18:25:56 by jgiacomo          #+#    #+#              #
#    Updated: 2022/08/08 18:26:01 by jgiacomo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror
FILES = ft_printf.c ft_printf_char.c ft_printf_hex.c ft_printf_numbers.c ft_printf_utils.c

OBJ = $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(OBJ) $(NAME)

re: fclean	all

.PHONY: all clean fclean re
