/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** No file there, just an epitech header example
*/

#include "include/my.h"
#include "include/tools.h"
#include "./include/my_inf_add.h"
#include <stdlib.h>

int my_putstrnbr(char const *str);

char *inf_add_nb_zero(char *nb, int *retenu, int *i, char *result)
{
    int nb_tmp;

    for (; nb[*i] != '\0'; (*i)++) {
        nb_tmp = nb[*i] - '0' + *retenu;
        *retenu = nb_tmp / 10;
        result = malloc_digit(result, *i);
        result[*i] = nb_tmp % 10 + '0';
    }
    return result;
}

char *inf_add_three(char *nb1, char *nb2)
{
    int nb_tmp = 0;
    int retenu = 0;
    char *result = NULL;
    int i = 0;

    for (;nb1[i] != '\0' && nb2[i] != '\0'; i++) {
        nb_tmp = nb1[i] + nb2[i] - (2 * '0') + retenu;
        retenu = nb_tmp / 10;
        result = malloc_digit(result, i);
        result[i] = nb_tmp % 10 + '0';
    }
    if (nb1[i] != '\0')
        result = inf_add_nb_zero(nb1, &retenu, &i, result);
    else
        result = inf_add_nb_zero(nb2, &retenu, &i, result);
    if (retenu != 0) {
        result = malloc_digit(result, i + 1);
        result[i] = retenu + '0';
    }
    return result;
}

char *inf_add_two(char *nb1, char *nb2)
{
    char *result;

    my_revstr(nb1);
    my_revstr(nb2);
    result = inf_add_three(nb1, nb2);
    my_revstr(result);
    return result;
}

char *inf_add(char *str1, char *str2)
{
    char *result;
    int is_neg = 0;

    if (str2[0] == '-' && str1[0] == '-') {
        is_neg = 1;
        result = inf_add_two(&str1[1], &str2[1]);
    }
    if (str2[0] == '-' && str1[0] != '-')
        result = inf_sub(&str1[0], &str2[1]);
    if (str2[0] != '-' && str1[0] == '-')
        result = inf_sub(&str2[0], &str1[1]);
    if (str2[0] != '-' && str1[0] != '-')
        result = inf_add_two(str1, str2);
    return my_putstr_l_z(result, is_neg);
}