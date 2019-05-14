##
## EPITECH PROJECT, 2017
## project
## File description:
## project
##

SRC	=	src/main.c		\
		src/utility.c		\
		src/manual_command.c	\
		src/modifie_env.c

NAME	=	mysh

OBJ	=	$(SRC:.c=.o)

LIBPATH	=	lib

LIBNAME	=	my

CFLAGS	=	-Iinclude/ -W -Werror -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	cd lib/my && make
	gcc -o $(NAME) $(CFLAGS) $(SRC) -L $(LIBPATH) -l$(LIBNAME)

clean:
	cd lib/my && make clean
	rm -f $(OBJ)

fclean: clean
	cd lib/my && make fclean
	rm -f $(NAME)

re: fclean all
