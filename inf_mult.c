/*
** EPITECH PROJECT, 2019
** inf_mult.c
** File description:
** Infinit Mult
*/

#include <stdlib.h>
#include <unistd.h>
#include "include/my.h"
#include "include/tools.h"

char *my_memset(char *s, char c, int n)
{
    for (int i = 0; i < n; i++) {
        s[i] = c;
    }
    return s;
}

char *inf_mult_two(char *result, char *nb1, char *nb2, char const *base)
{
    int i;
    int len_base = my_strlen(base);
    int tmp;
    int carry = 0;
    int j;

    for (i = 0; nb2[i] != '\0'; i++) {
        carry = 0;
        for (j = 0; nb1[j] != '\0'; j++) {
            tmp = carry + base_i(nb1[j], base) * base_i(nb2[i], base) +
                base_i(result[i+j], base);
            carry = tmp / len_base;
            result[i+j] = base[tmp % len_base];
        }
        result[i+j] = base[carry];
        j++;
    }
    result[i+j] = '\0';
    return my_revstr(result);
}

char *inf_mult(char *nb1, char *nb2, char const *base, char *sp)
{
    int len_result = my_strlen(nb1) + my_strlen(nb2);
    char *result = malloc(sizeof(char)*(len_result + 1));
    char *cp1;
    char *cp2;

    if (!result)
        return (NULL);
    my_memset(result, base[0], len_result);
    cp1 = my_revstr(my_strdup(nb1));
    cp2 = my_revstr(my_strdup(nb2));
    result = inf_mult_two(result, cp1, cp2, base);
    return my_putstr_l_z(result, 0, sp[3]);
}
