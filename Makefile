##
## EPITECH PROJECT, 2019
## Main Makefile
## File description:
## Makefile
##

SRC	=	main.c		\
		inf_mult.c	\
		inf_sub.c	\
		inf_add.c	\
		my_putstrnbr.c	\
		modifstr.c \
		evalexpr.c \
		my_strcmp.c \
		tools.c

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

.PHONY: re clean fclean all
