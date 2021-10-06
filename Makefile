# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 01:17:01 by jamrabhi          #+#    #+#              #
#    Updated: 2021/10/06 01:17:05 by jamrabhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = clang

CFLAGS = -Wall -Wextra -Werror

SRC = src/main.c src/parsing/print_error.c src/get_next_line/get_next_line.c \
		src/get_next_line/get_next_line_utils.c src/parsing/parsing.c \
		src/parsing/parse_path.c src/parsing/parse_RGB.c \
		src/parsing/parse_map.c src/parsing/parse_map_utils.c

OBJ = $(SRC:.c=.o)

LIBDIR = lib/libft

LIB = lib/libft/libft.a

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME) : $(OBJ)
	cd $(LIBDIR) && make
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

clean:
	cd $(LIBDIR) && make clean
	rm -f $(OBJ)

fclean: clean
	cd $(LIBDIR) && make fclean
	rm -f $(NAME)

re: fclean all
