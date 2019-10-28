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

int main(int argc, char **argv)
{
    char expression[4096];
    read(STDIN_FILENO, expression, 4096);
    if (argc >= 4) {
        my_put_nbr(eval_expr(modifstr(expression)));
        //my_putchar('\n');
        return 0;
    }
    return (84);
}
