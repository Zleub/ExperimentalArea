# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adebray <adebray@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/16 20:25:00 by adebray           #+#    #+#              #
#    Updated: 2014/01/12 17:30:11 by adebray          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = ft_select
LIBNAME = ./src/libselect.a
SRCDIR = ./src/
HEADDIR = ./inc/

SRC = ./src/gnl.c \
		./src/ft_strcsplit.c \
		./src/ft_putschar.c \
		./src/crown.c \
		./src/list.c \
		./src/print.c \
		./src/read.c \
		./src/signal.c

OBJ = $(subst .c,.o,$(SRC))

CC = gcc
CCFLAGS = -Werror -Wall -Wextra -Wuninitialized -g3 -O3
LIBFLAG = -L./src/ -L./src/libft -L./src/ft_printf -lselect -lft -lftprintf
LIBSYS = -ltermcap
HEADFLAG = -I$(HEADDIR)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): libft printf $(LIBNAME) main.c
	$(CC) $(CCFLAGS) $(HEADFLAG) $(LIBFLAG) $(LIBSYS) -o $(NAME) main.c

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
