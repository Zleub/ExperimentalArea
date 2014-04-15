# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adebray <adebray@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/16 14:40:42 by adebray           #+#    #+#              #
#    Updated: 2014/04/15 20:48:25 by adebray          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_ls
HEADDIR		=	inc

SRC			=	./src/main.c \
				./src/manage.c \
				./src/basic.c \
				./src/print_dir.c \
				./src/clist.c \
				./src/array.c

OBJ			=	$(subst .c,.o,$(SRC))

CC			=	clang
CCFLAGS		=	-Werror -Wall -Wextra -Wuninitialized -g3 -O3

HEADFLAG	=	-I $(HEADDIR)

LIBLIBFT	=	-L./src/libft -lft
LIBPRINTF	=	-L./src/ft_printf -lftprintf

LIBFLAG		=	$(LIBLIBFT) $(LIBPRINTF)

.PHONY: all clean fclean re

all: makelib $(NAME)

makelib: libft printf

$(NAME): $(OBJ) ./src/ft_printf/libftprintf.a
	@$(CC) $(CCFLAGS) $(HEADFLAG) $(LIBFLAG) -o $(NAME) $(OBJ)
	@echo "\033[32m•\033[0m $(NAME) compil: \033[32m$(NAME)\033[0m"

libft: ./inc/libft.h ./inc/gnl.h
	@make -C ./src/libft

printf: ./inc/ft_printf.h
	@make -C ./src/ft_printf

%.o: %.c
	@$(CC) $(CCFLAGS) $(HEADFLAG) -o $@ -c $<

clean:
	@make -C ./src/libft clean
	@make -C ./src/ft_printf clean
	@rm -f $(OBJ)
	@echo "\033[31m•\033[0m $(NAME) clean.\033[0m"

fclean:
	@make -C ./src/libft fclean
	@make -C ./src/ft_printf fclean
	@rm -f $(OBJ)
	@rm -f $(LIBNAME)
	@rm -f $(NAME)
	@echo "\033[31m•\033[0m $(NAME) fclean: \033[31m$(NAME)\033[0m"

re: fclean all
