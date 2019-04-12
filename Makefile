##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	$(shell find -name '*.c')

NAME    =       matchstick

all:    $(NAME)

$(NAME):        $(SRC)
	gcc -I include  -o $(NAME) $(SRC) -g3
	rm -f $(shell find -name '*~')

clean:
	rm -f $(shell find -name '*~')
	rm -f $(shell find -name 'vgcore*')

fclean: clean
	rm -f $(NAME)

re:     fclean all

.PHONY: all clean fclean re
