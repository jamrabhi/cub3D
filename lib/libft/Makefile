# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 17:32:25 by jamrabhi          #+#    #+#              #
#    Updated: 2021/06/18 20:55:22 by jamrabhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HDR = libft.h

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
		ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
		ft_strrchr.c ft_tolower.c ft_toupper.c ft_strjoin.c ft_substr.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_isdigit_str.c \
		ft_strcmp.c ft_split_str.c ft_atol.c

SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ = $(SRCS:.c=.o)

OBJ_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	gcc -c -Wall -Wextra -Werror $(SRCS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

bonus: $(OBJ_BONUS)
ifeq ("$(shell ls -R $(OBJ_BONUS) 2>/dev/null)","")
	gcc -c -Wall -Wextra -Werror $(SRCS) $(SRCS_BONUS)
	ar rc $(NAME) $(OBJ) $(OBJ_BONUS) 
	ranlib $(NAME)
endif

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all
