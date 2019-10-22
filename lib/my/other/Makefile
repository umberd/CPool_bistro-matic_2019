##
## EPITECH PROJECT, 2019
## CPool_Day03_2019
## File description:
## No file there, just an epitech header example
##

SRC	=	$(shell find *.c)	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar -rc -o $(NAME) $(OBJ)
	cp my.h ../../../include/
	cp libmy.a ../..
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../../../include/my.h
	rm -f ../../libmy.a

re:	fclean all

.PHONY : re clean fclean