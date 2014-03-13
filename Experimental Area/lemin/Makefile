# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adebray <adebray@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/16 20:25:00 by adebray           #+#    #+#              #
#    Updated: 2014/03/13 15:07:32 by adebray          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME		= lem-in
LIBNAME		= ./src/liblemin.a
LIBFT		= ./src/libft/libft.a
PRINTF		= ./src/ft_printf/libftprintf.a

SRCDIR		= ./src/
HEADDIR		= ./inc/

SRC			=	./src/gnl.c				\
				./src/is_something.c	\
				./src/start_end.c		\
				./src/t_data.c			\
				./src/t_gnl.c			\
				./src/t_pipe.c			\
				./src/t_room.c

OBJ			= $(subst .c,.o,$(SRC))

CC			= gcc
CCFLAGS		= -Werror -Wall -Wextra -Wuninitialized -g3 -O3
LIBFLAG		= -L./src/ -llemin -L./src/libft -lft -L./src/ft_printf -lftprintf
SYSFLAG		= -ltermcap
HEADFLAG	= -I$(HEADDIR)

.PHONY: all clean fclean re $(LIBFT) $(PRINTF)

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(LIBNAME) main.c
	$(CC) $(HEADFLAG) $(LIBFLAG) $(SYSFLAG) -o $(NAME) main.c

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
