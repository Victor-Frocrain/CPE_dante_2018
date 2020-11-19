##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

##all:	$(NAME)

all:
	make -C lib/my/
	make -C generator/
	make -C solver/

clean:
	make -C lib/my/ clean
	make -C generator/ clean
	make -C solver/ clean

fclean:		clean
	make -C lib/my/ fclean
	make -C generator/ fclean
	make -C solver/ fclean

re:	fclean all
	make -C lib/my/ re
	make -C generator/ re
	make -C solver/ re
