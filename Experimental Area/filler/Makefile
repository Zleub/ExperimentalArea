# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adebray <adebray@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/16 20:25:00 by adebray           #+#    #+#              #
#    Updated: 2014/01/24 07:19:43 by adebray          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = filler
LIBNAME = ./src/libfiller.a
SRCDIR = ./src/
HEADDIR = ./inc/

SRC = ./src/gnl.c \
		./src/ft_strcsplit.c \
		./src/ft_putschar.c \

OBJ = $(subst .c,.o,$(SRC))

CC = cc
CCFLAGS = -Werror -Wall -Wextra -Wuninitialized -g3 -O3
LIBFLAG = -L./src/ -L./src/libft -L./src/ft_printf -lfiller -lft -lftprintf
HEADFLAG = -I$(HEADDIR)

.PHONY: all clean fclean re

all: libft printf $(LIBNAME) $(NAME)

$(NAME): main.c
	$(CC) $(CCFLAGS) $(HEADFLAG) $(LIBFLAG) -o $(NAME) $^

$(LIBNAME): $(OBJ)
	ar rc $@ $^
	ranlib $@

printf:
	make -C ./src/ft_printf

libft:
	make -C ./src/libft

%.o: %.c
	$(CC) $(CCFLAGS) $(HEADFLAG) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIBNAME)
	rm -f $(NAME)

re: fclean all
