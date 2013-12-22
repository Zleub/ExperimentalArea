# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adebray <adebray@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/16 20:25:00 by adebray           #+#    #+#              #
#    Updated: 2013/12/22 14:18:42 by adebray          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = ft_printf
LIBNAME = libftprintf.a
SRCDIR = ./src/
HEADDIR = ./inc/
FTHEADDIR = ./src/libft/includes

SPC :=
SPC +=

SRC = ./src/ft_printf.c \
		./src/ft_putchar.c \
		./src/ft_putstr.c \
		./src/gnl.c \
		./src/ft_strlen.c \
		./src/ft_putnbr.c \
		./src/ft_octal.c \
		./src/ft_hexa.c \
		./src/ft_sheum_hexa.c \
		./src/tools.c

OBJ = $(subst .c,.o,$(SRC))

CC = gcc
CCFLAGS = -Werror -Wall -Wextra -g
LIBFLAG = -L./ -L./src/libft -lftprintf -lft
HEADFLAG = -I $(HEADDIR) -I $(FTHEADDIR)

.PHONY: all lib clean fclean re

all: $(NAME)

$(NAME): $(LIBNAME) main.c
	$(CC) $(CCFLAGS) -o $(NAME) $(HEADFLAG) $(LIBFLAG) main.c

$(LIBNAME): $(OBJ)
	ar rc $@ $^
	ranlib $@

libft:
	cd src/libft/; make

clean:
	rm -f $(OBJ)

%.o: %.c
	$(CC) $(CCFLAGS) $(HEADFLAG) -o $@ -c $<

fclean: clean
	rm -f $(LIBNAME)
	rm -f $(NAME)

re: fclean all
