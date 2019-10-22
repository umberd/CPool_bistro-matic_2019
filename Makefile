##
## EPITECH PROJECT, 2019
## CPool_Day03_2019
## File description:
## No file there, just an epitech header example
##

SRC	=	main.c		\

NAME	=	calc

LIBDIR	=	lib/my

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C $(LIBDIR)
	gcc -o $(NAME) $(SRC) -L./lib/ -lmy
	
clean:
	make clean -C $(LIBDIR)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBDIR)
	rm -f $(NAME)

re:	fclean all

.PHONY: re clean fclean