/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** No file there, just an epitech header example
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"
#include "include/tools.h"
#include "include/my_inf_add.h"

char *inf_add_three(char *nb1, char *nb2, char *base, int len_base)
{
    int nb_tmp = 0;
    int retenu = 0;
    char *result = malloc(sizeof(char) * (my_strlen(nb1) + my_strlen(nb2) + 5000));
    int i = 0;
    int j = 0;
    int digit1;
    int digit2;
    while (nb1[i] != '\0' || nb2[j] != '\0') {
        digit1 = base_i(nb1[i], base) < 0 ? 0: base_i(nb1[i], base);
        digit2 = base_i(nb2[j], base) < 0 ? 0: base_i(nb2[j], base);
        nb_tmp = digit1 + digit2 + retenu;
        retenu = nb_tmp / len_base;
        result[i > j ? i : j] = base[nb_tmp % len_base];
        i = nb1[i] != '\0' ? i + 1 : i;
        j = nb2[j] != '\0' ? j + 1 : j;
    }
    result[i > j ? i : j] = retenu != 0 ? base[retenu] : result[i > j ? i : j];
    return result;
}

char *inf_add_two(char *nb1, char *nb2, char *base)
{
    char *result;
    int len_base = my_strlen(base);
    my_revstr(nb1);
    my_revstr(nb2);
    result = inf_add_three(nb1, nb2, base, len_base);
    my_revstr(result);
    return result;
}

char *inf_add(char *str1, char *str2, char *base, char *sp)
{
    char *result;
    int is_neg = 0;

    printf("CHECK %s %s \n", str1, str2);
    if (str2[0] == sp[3] && str1[0] == sp[3]) {
        is_neg = 1;
        result = inf_add_two(&str1[1], &str2[1], base);
    }
    if (str2[0] == sp[3] && str1[0] != sp[3])
        result = inf_sub(&str1[0], &str2[1], base, sp);
    if (str2[0] != sp[3] && str1[0] == sp[3])
        result = inf_sub(&str2[0], &str1[1], base, sp);
    if (str2[0] != sp[3] && str1[0] != sp[3])
        result = inf_add_two(str1, str2, base);
    return my_putstr_l_z(result, is_neg, sp[3], base[0]);
}