##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	../sources/solver/main.c		\
		../sources/solver/solver.c		\
		../sources/solver/free_all.c		\
		../sources/solver/display_result.c	\
		../sources/solver/compute_result.c	\

OBJ	=	$(SRC:%.c=%.o)

NAME	=	solver

CFLAGS	=	-I ../include/ -W

CC	=	gcc

LIB	=	-L ../lib/my/ -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ../lib/my/
	$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
	make -C ../lib/my/ clean
	rm -f $(OBJ)

fclean:		clean
	make -C ../lib/my/ fclean
	rm -f $(NAME)

re:	fclean all
	make -C ../lib/my/ re
