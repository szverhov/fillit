# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 14:39:42 by vlvereta          #+#    #+#              #
#    Updated: 2017/11/06 14:45:17 by vlvereta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc 

FLAGS = -Wall -Wextra -Werror

OBJ = ./fillit.o ./auxiliary_functions.o ./file_checker.o \
./list_functions.o ./matrix_creator.o ./matrix_functions.o \

LIBFT = make -C $(L_DIR) re

L_DIR = ./libft

all: $(NAME)

$(NAME): $(OBJ)
	$(LIBFT)
	$(CC) -o $(NAME) $(OBJ) -L./libft/ -lft

%.o: %.c
	$(CC) -o $@ -c $< $(FLAGS)

clean: libft_clean
	rm -f $(OBJ)

libft_clean:
	make -C $(L_DIR) clean

fclean: clean libft_fclean
	rm -f $(NAME)

libft_fclean:
	make -C $(L_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
