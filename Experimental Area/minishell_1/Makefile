# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adebray <adebray@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/16 20:25:00 by adebray           #+#    #+#              #
#    Updated: 2013/12/27 04:07:22 by adebray          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = ft_minishell1
LIBNAME = ./src/libminishell1.a
SRCDIR = ./src/
HEADDIR = ./inc/

SRC = ./src/gnl.c

OBJ = $(subst .c,.o,$(SRC))

CC = gcc
CCFLAGS = -Werror -Wall -Wextra -g
LIBFLAG = -L./src/ -L./src/ft_printf -lminishell1 -lftprintf
HEADFLAG = -I$(HEADDIR)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): libft printf $(LIBNAME) main.c
	$(CC) $(CCFLAGS) $(HEADFLAG) $(LIBFLAG) -o $(NAME) main.c

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
