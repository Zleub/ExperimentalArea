# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adebray <adebray@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/16 20:25:00 by adebray           #+#    #+#              #
#    Updated: 2014/03/07 22:37:49 by adebray          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME		= puissance4
LIBNAME		= ./src/libpuissance4.a
LIBFT		= ./src/libft/libft.a
PRINTF		= ./src/ft_printf/libftprintf.a

SRCDIR		= ./src/
HEADDIR		= ./inc/

SRC			=	./src/gnl.c

OBJ			= $(subst .c,.o,$(SRC))

CC			= gcc
CCFLAGS		= -Werror -Wall -Wextra -Wuninitialized -g3 -O3
LIBFLAG		= -L./src/ -lpuissance4 -L./src/libft -lft -L./src/ft_printf -lftprintf
#SYSFLAG		= -ltermcap
HEADFLAG	= -I$(HEADDIR)

.PHONY: all clean fclean re $(LIBFT) $(PRINTF)

all: $(LIBFT) $(PRINTF) $(LIBNAME) $(NAME)

$(NAME): main.c
	$(CC) $(CCFLAGS) $(HEADFLAG) $(LIBFLAG) -o $(NAME) main.c

$(LIBNAME): $(OBJ)
	ar rc $@ $^
	ranlib $@

$(PRINTF):
	make -C ./src/ft_printf

$(LIBFT):
	make -C ./src/libft

%.o: %.c
	$(CC) $(CCFLAGS) $(HEADFLAG) -o $@ -c $<

clean:
	make -C ./src/ft_printf clean
	make -C ./src/libft clean
	rm -f $(OBJ)

fclean: clean
	make -C ./src/ft_printf fclean
	make -C ./src/libft fclean
	rm -f $(LIBNAME)
	rm -f $(NAME)

re: fclean all
