##
## EPITECH PROJECT, 2019
## CPool_Day03_2019
## File description:
## No file there, just an epitech header example
##

SRC	=	main.c		\
		inf_mult.c	\
		inf_sub.c	\
		inf_add.c	\
		my_putstrnbr.c	\
		modifstr.c \
		evalexpr.c \
		my_strcmp.c

NAME	=	calc

LIBDIR	=	lib/my/other
LIBDIR2	=	lib/my/btree

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C $(LIBDIR)
	make -C $(LIBDIR2)
	gcc -o $(NAME) $(SRC) -L./lib/ -lmy -lbtree
	
clean:
	make clean -C $(LIBDIR)
	make clean -C $(LIBDIR2)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBDIR)
	make fclean -C $(LIBDIR2)
	rm -f $(NAME)

re:	fclean all

.PHONY: re clean fclean