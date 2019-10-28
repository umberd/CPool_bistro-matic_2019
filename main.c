/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** Adding stuff together
*/

#include "include/my.h"
#include "include/my_inf_add.h"
#include <unistd.h>
#include <sys/wait.h>

char *modifstr(char *str);

char *eval_expr(char const *s);

char *inf_mult(char *nb1, char *nb2, char const *base);

char *infinite_sub(char *s1, char * s2);

int main(int argc, char **argv)
{
    char expression[4096];
    read(STDIN_FILENO, expression, 4096);
    char *s1 = "0";
    char *s2 = "40";
    if (argc >= 4) {
        //my_putstr(inf_sub(s1, s2));
        my_putstr(eval_expr(modifstr(expression)));
        //my_putchar('\n');
        return 0;
    }
    return (84);
}
