NAME = ft_ls
LIBNAME = libls.a
LIBFT = libft.a

LIBDIR = ./libft
SRCDIR = ./src/
HEADDIR = ./inc/

SPC :=
SPC +=

SRC = $(subst $(SPC),$(SPC)$(SRCDIR),$(SRCDIR)$(shell ls $(SRCDIR) | grep .c))

OBJ = $(subst .c,.o,$(shell ls $(SRCDIR) | grep .c))

CC = gcc
CCFLAGS = -Werror -Wall -Wextra -L./libft -lft -I./libft/includes

.PHONY: all lib clean fclean re

all: $(NAME)

$(NAME): lib clean
	cd $(LIBDIR); make
	$(CC) $(CCFLAGS) -o $(NAME) -I./inc $(LIBNAME) main.c

lib: $(SRC)
	$(CC) -I $(HEADDIR) -c $(SRC)
	ar rc $(LIBNAME) $(OBJ)
	ranlib $(LIBNAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIBNAME)
	rm -f $(NAME)

re: all
