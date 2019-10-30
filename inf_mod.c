/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** No file there, just an epitech header example
*/
#include"include/my.h"
#include<stdlib.h>
#include<stdio.h>

char *inf_mult(char *nb1, char *nb2, char const *base);

char *inf_sub(char *str1, char *str2);

char *my_putstr_l_z(char *result, int is_neg);

int my_strcmpp(char const *s1, char const *s2);

char *getstr_from_to(char *str, int start, int end);

char single_divisor(char *nb_a, char *nb_b, char *base);

char *inf_mod_two(char *nb_a, char *nb_b, char *a, char *base)
{
    char *c = malloc(sizeof(char) * 2);
    int len_nb_a = my_strlen(nb_a);
    int len_a = my_strlen(a);
    char *res = malloc(sizeof(char) * len_a);
    char *rst = malloc(sizeof(char) * len_a);
    char *chr = malloc(sizeof(char) * 2);

    for (int i = 0; i < len_a; res[i] = '\0', rst[i] = '\0', i++);
    for (int i = 0; i < len_a - len_nb_a + 1; i++) {
        c[0] = single_divisor(nb_a, nb_b, base);
        res = my_strcat(res, c);
        rst = inf_sub(nb_a, inf_mult(nb_b, c, base));
        chr[0] = a[len_nb_a + i];
        nb_a = (rst[0] == '0') ? chr : my_strcat(rst, chr);
    }
    return rst;
}

char *inf_mod(char *a, char *b, char *base)
{
    char *res = NULL;
    int len_a = my_strlen(a);
    int len_b = my_strlen(b);
    char *nb_a = NULL;
    char *nb_b = NULL;

    if (my_strcmpp(a, b) < 0)
        return a;
    nb_a = getstr_from_to(a, 0, len_b);
    nb_b = getstr_from_to(b, 0, len_b);
    if (my_strcmpp(nb_a, nb_b) < 0){
        free(nb_a);
        nb_a = getstr_from_to(a, 0, len_b);
    }
    res = inf_div_two(nb_a, nb_b, a, base);
    return my_putstr_l_z(res, 0);
}