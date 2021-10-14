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

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = src/main.c src/parsing/print_error.c src/get_next_line/get_next_line.c \
		src/get_next_line/get_next_line_utils.c src/parsing/parsing.c \
		src/parsing/parse_path.c src/parsing/parse_RGB.c \
		src/parsing/parse_map.c src/parsing/parse_map_utils.c

OBJ = $(SRC:.c=.o)

LIBDIR = lib/libft/

LIB = lib/libft/libft.a

MLXDIR = minilibx-linux/

MLX = libmlx_Linux.a

MAKEFLAGS += --no-print-directory

all: $(NAME)

$(NAME) : $(OBJ)
	@echo "Compiling libft ..."
	@cd $(LIBDIR) && make
	@echo "DONE \n"

	@echo "Configuring MiniLibX ..."
	@cd $(MLXDIR) && ./configure > /dev/null 2>&1
	@echo "DONE \n"

	@echo "Compiling cub3D ..."
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)
	@echo "DONE \n"

.c.o:
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@echo "Deleting Libft objects files ..."
	@cd $(LIBDIR) && make $@
	@echo "DONE \n"

	@echo "Deleting cub3D objects files ..."
	@rm -f $(OBJ)
	@echo "DONE \n"

fclean: clean
	@echo "Executing the clean rule of MiniLibX ..."
	@cd $(MLXDIR) && ./configure clean > /dev/null 2>&1
	@echo "DONE \n"

	@echo "Deleting Libft's binary ..."
	@cd $(LIBDIR) && make $@
	@echo "DONE \n"
	
	@echo "Deleting cub3D's binary ..."
	@rm -f $(NAME)
	@echo "DONE \n"

re: fclean all
