# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/25 11:05:36 by gschaetz          #+#    #+#              #
#    Updated: 2017/05/13 17:02:03 by gschaetz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gschaetz.filler

LIBFT = libft/libft.a

FLAG = -Wextra -Werror -Wall

INC = include/filler.h

SRC = src/main.c src/malloc.c src/ft_identifi.c src/stock_for_map.c \
	  src/stock_for_piece.c src/free.c src/identifi_little.c \
	  src/positioning.c src/ft_superpose.c src/count.c \
	  src/ft_count_nb_link1.c src/compare.c \
	  src/ft_count_nb_point_little.c src/ft_determine_start_position.c \
	  src/ft_touch_bord.c src/ft_piece.c src/ft_map.c \
	  src/ft_check_and_try_pos.c

all: $(NAME)

$(NAME): $(LIBFT) $(SRC)
	gcc -o $(NAME) $(FLAG) $(SRC) -Llibft -lft

$(LIBFT):
	make -C libft

$(LIBFTP):
	make -C libftp

clean:
	make -C libft clean

fclean: clean
	make -C libft fclean
	rm $(NAME)

re: fclean all
	
.PHONY: all fclean re clean
