##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile to build project
##

CC		=	gcc

FLAGS		=	-Werror -Wall -Wextra

MAIN		=	main.c

SRC		=	inf_mult.c	\
			inf_sub.c	\
			inf_add.c	\
			inf_div.c	\
			inf_mod.c	\
			my_putstrnbr.c	\
			modifstr.c \
			evalexpr.c \
			my_strcmp.c	\
			error.c \
			tools.c

OBJ     	=       $(SRC:.c=.o) $(MAIN:.c=.o)

NAME    	=       calc

INCLUDE 	=       ./include

LIB_FOLDER      =       ./lib/my

LIB_NAME        =       my

TEST		=	evalexpr.c \
			tests/test_evalexpr.c

TEST_FLAG	=	--coverage -lcriterion

TEST_NAME	=	unit_tests

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C $(LIB_FOLDER)
		$(CC) -o $(NAME) $(OBJ) -I$(INCLUDE) -L$(LIB_FOLDER) -l$(LIB_NAME) $(FLAGS)

clean:
		rm -f $(OBJ)
		cd $(LIB_FOLDER) && make clean
		rm -f *~
		rm -f *#

fclean:		clean
		cd $(LIB_FOLDER) && make fclean
		rm -f $(NAME)
		rm -f $(TEST_NAME)
		rm -f *.gcda
		rm -f *.gcno

tests_run:	all
		$(CC) $(FLAGS) -o $(TEST_NAME) $(TEST) $(TEST_FLAG) -I$(INCLUDE) -L$(LIB_FOLDER) -l$(LIB_NAME) && ./$(TEST_NAME)

re:		fclean all
		cd $(LIB_FOLDER) && make re

auteur:
		echo $(USER) > auteur

.PHONY: 	all clean fclean re tests_run
