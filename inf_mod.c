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

char *under_ff(char *a, char *nb_a, char *nb_b, int len_b)
{
    if (my_strcmpp(nb_a, nb_b) < 0){
        free(nb_a);
        nb_a = getstr_from_to(a, 0, len_b);
    }
    return nb_a;
}

char *inf_mod(char *a, char *b, char *base)
{
    if (my_strcmpp(a, b) < 0)
        return a;
    int len_a = my_strlen(a);
    int len_b = my_strlen(b);
    char *nb_a = getstr_from_to(a, 0, len_b);
    char *nb_b = getstr_from_to(b, 0, len_b);
    nb_a = under_ff(a, nb_a, nb_b, len_b);
    char *res = malloc(sizeof(char) * len_a);
    char *rst = malloc(sizeof(char) * len_a);
    for (int i = 0; i < len_a; res[i] = '\0', rst[i] = '\0', i++);
    int len_nb_a = my_strlen(nb_a);
    for (int i = 0; i < len_a - len_nb_a + 1; i++) {
        char c[] = {single_divisor(nb_a, nb_b, base), '\0'};
        res = my_strcat(res, c);
        rst = inf_sub(nb_a, inf_mult(nb_b, c, base));
        char chr[] = {a[len_nb_a + i], '\0'};
        nb_a = (rst[0] == '0') ? chr : my_strcat(rst, chr);
    }
    return rst;
}