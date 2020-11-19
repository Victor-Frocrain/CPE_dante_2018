##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	../sources/generator/main.c		\
		../sources/generator/generator.c	\
		../sources/generator/init_generator.c	\
		../sources/generator/display_line.c	\
		../sources/generator/extrude.c		\
		../sources/generator/manage_id.c	\
		../sources/generator/fill_lines.c	\
		../sources/generator/manage_lines.c	\

OBJ	=	$(SRC:%.c=%.o)

NAME	=	generator

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
