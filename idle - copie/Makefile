# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adebray <adebray@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/16 20:25:00 by adebray           #+#    #+#              #
#    Updated: 2013/12/19 06:07:22 by adebray          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = idle
LIBNAME = libidle.a
SRCDIR = ./src/
HEADDIR = ./inc/
FTHEADDIR = ./src/libft/includes

SPC :=
SPC +=

SRC = ./src/gnl.c		\
	./src/hello.c		\
	./src/hashich.c		\
	./src/ft_fibonacci.c\
	./src/print.c 		\
	./src/chest.c		\
	./src/management.c	\
	./src/doer.c

OBJ = $(subst .c,.o,$(SRC))

CC = gcc
CCFLAGS = -Werror -Wall -Wextra -g
LIBFLAG = -L./ -L./src/libft -lidle -lft
HEADFLAG = -I $(HEADDIR) -I $(FTHEADDIR)

.PHONY: all lib clean fclean re

all: $(NAME)

$(NAME): libft $(LIBNAME)
	$(CC) $(CCFLAGS) -o $(NAME) $(HEADFLAG) $(LIBFLAG) main.c

$(LIBNAME): $(OBJ)
	ar rc $@ $^
	ranlib $@

libft:
	cd src/libft/; make

%.o: %.c
	$(CC) $(CCFLAGS) $(HEADFLAG) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIBNAME)
	rm -f $(NAME)

re: all
