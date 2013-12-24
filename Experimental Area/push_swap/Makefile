# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adebray <adebray@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/16 20:25:00 by adebray           #+#    #+#              #
#    Updated: 2013/12/24 21:03:53 by adebray          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = push_swap
LIBNAME = ./src/libpushswap.a
SRCDIR = ./src/
HEADDIR = ./inc/

SRC = ./src/ft_initial.c \
		./src/ft_putendl_fd.c \
		./src/ft_putchar_fd.c \
		./src/ft_printargv.c \
		./src/ft_issomething.c \
		./src/ft_interactive.c \
		./src/ft_print.c \
		./src/ft_swap.c \
		./src/ft_push.c \
		./src/ft_reverse.c \
		./src/ft_rreverse.c \
		./src/gnl.c


OBJ = $(subst .c,.o,$(SRC))

CC = gcc
CCFLAGS = -Werror -Wall -Wextra -g
LIBFLAG = -L./src/ -L./src/ft_printf -lpushswap -lftprintf
HEADFLAG = -I$(HEADDIR)

.PHONY: all lib clean fclean re

all: $(NAME)

$(NAME): printf $(LIBNAME) main.c
	$(CC) $(CCFLAGS) $(HEADFLAG) $(LIBFLAG) -o $(NAME) main.c

$(LIBNAME): $(OBJ)
	ar rc $@ $^
	ranlib $@

printf:
	make -C ./src/ft_printf

%.o: %.c
	$(CC) $(CCFLAGS) $(HEADFLAG) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIBNAME)
	rm -f $(NAME)

re: fclean all
