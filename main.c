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

char *inf_div(char *a, char *b, char *base);

int error_test(char *str, char *base, char *spec);

int main(int argc, char **argv)
{
    char expression[4096];
    read(STDIN_FILENO, expression, 4096);
    char *s1 = "0";
    char *s2 = "4";
    char *base = argv[1];
    char *spec = argv[2];
    
    if (argc >= 4) {
        if (error_test(expression,base,spec))
            return 1;
        my_putstr(eval_expr(modifstr(expression)));
        return 0;
    }
    return (84);
}