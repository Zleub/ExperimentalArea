NAME = program_name
LIBNAME = program_lib.a
SRCDIR = ./src/
HEADERDIR = ./inc/

SPC :=
SPC +=

SRC = $(subst $(SPC),$(SPC)$(SRCDIR),$(SRCDIR)$(shell ls $(SRCDIR) | grep .c))

OBJ = $(subst .c,.o,$(shell ls $(SRCDIR) | grep .c))

CC = gcc
CCFLAGS = -Werror -Wall -Wextra

.PHONY: all lib clean fclean re

all: $(NAME)

$(NAME): lib clean
	$(CC) $(CCFLAGS) -o $(NAME) $(LIBNAME) main.c

lib:
	$(CC) -I $(HEADERDIR) -c $(SRC)
	ar rc $(LIBNAME) $(OBJ)
	ranlib $(LIBNAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIBNAME)
	rm -f $(NAME)

re: all
