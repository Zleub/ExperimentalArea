#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adebray <adebray@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 11:21:22 by adebray           #+#    #+#              #
#    Updated: 2013/11/19 16:08:21 by adebray          ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME = libft.a
LIB	= ft
HEADDIR = ./

SRC = $(shell ls | fgrep .c)
OBJ = $(subst .c,.o,$(SRC))

CC = cc
CCFLAGS = -Werror -Wall -Wextra

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): clean
	$(CC) -I $(HEADDIR) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	make clean

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: all
