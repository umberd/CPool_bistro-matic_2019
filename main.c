/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** Adding stuff together
*/

#include "include/my.h"
#include <unistd.h>
#include <sys/wait.h>

char *modifstr(char *str);

int eval_expr(char const *s);

char *inf_mult(char *nb1, char *nb2, char const *base);

int error_test(char *str, char *base, char *spec);

int main(int argc, char **argv)
{
    char expression[4096];
    read(STDIN_FILENO, expression, 4096);
    char *base = argv[1];
    char *spec = argv[2];
    if (error_test(expression,base,spec)) {
        my_putstr("Syntax error");
        return 1;
    }
    if (argc >= 4) {
        my_putstr(modifstr(expression));
        return 0;
    }
    return (84);
}
