/*
** EPITECH PROJECT, 2019
** my_inf_add.c
** File description:
** my_inf_add
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"
#include "include/tools.h"
#include "include/my_inf_add.h"
#include "include/my_macro_abs.h"

char *my_strcpy_spec(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    while (dest[i] != '\0')
        dest[i] = '0';
    return dest;
}

char *nb_comp_equalize(char *result, int len_result)
{
    my_revstr(result);
    result = malloc_digit(result, len_result);
    for (int i = 0; i < len_result; i++)
        if (result[i] < '0' || result[i] > '9')
            result[i] = '0';
    return my_revstr(result);
}

char *nb_complement(char *nb, char *base)
{
    int len_base = my_strlen(base);

    for (int i = 0; nb[i] != '\0'; i++) {
        nb[i] = base[len_base - base_i(nb[i], base) - 1];
    }
    return nb;
}

char *inf_sub_two(char *nb1, char *nb2, int *is_neg, char *base)
{
    char tmp[] = "1";
    int len1 = nb1 != NULL ? my_strlen(nb1) : 0;
    int len2 = nb2 != NULL ? my_strlen(nb2) : 0;
    char *result = NULL;
    char *nb1_cpy = my_strdup(nb1);
    char *nb2_cpy = my_strdup(nb2);

    if (len1 > len2)
        nb2_cpy = nb_comp_equalize(nb2_cpy, len1);
    nb2_cpy = nb_complement(nb2_cpy, base);
    result = inf_add_two(nb1_cpy, nb2_cpy, base);
    if ((my_strlen(result) > len1) && (my_strlen(result) > len2))
        return (inf_add_two(result, tmp, base) + 1);
    *is_neg = 1;
    return nb_complement(result, base);
}


char *inf_sub(char *str1, char *str2, char *base, char *sp)
{
    char *result;
    int is_neg = 0;

    if (str1[0] == sp[3] && str2[0] == sp[3])
        result = inf_sub_two(&str2[1], &str1[1], &is_neg, base);
    if (str1[0] == sp[3] && str2[0] != sp[3]) {
        is_neg = 1;
        result = inf_add(&str1[1], &str2[0], "0123456789", sp);
    }
    if (str1[0] != sp[3] && str2[0] == sp[3])
        result = inf_add(&str1[0], &str2[1], "0123456789", sp);
    if (str1[0] != sp[3] && str2[0] != sp[3])
        result = inf_sub_two(str1, str2, &is_neg, base);
    return my_putstr_l_z(result, 1, sp[3]);
}
