/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** No file there, just an epitech header example
*/

#include <stdlib.h>
#include "include/my.h"

int char_in_array(char c, char *str);

void my_strxcat(char *res, char c, int x);

void custom_triple_cat(char *res, char a, char b, char c);

void custom_triple_cat2(char *res, char a, char b, char c);

void custom_double_cat(char *res, char a, char b);

void another_newf(char *str, int i, char *res, char *spec)
{
    if (str[i] == spec[4])
        custom_triple_cat(res, spec[1], spec[4], spec[0]);
    if (str[i] == spec[5])
        custom_triple_cat(res, spec[1], spec[5], spec[0]);
    if (str[i] == spec[6])
        custom_triple_cat(res, spec[1], spec[6], spec[0]);
    if (str[i] == spec[0])
        my_strxcat(res, spec[0], 2);
    if (str[i] == spec[1])
        my_strxcat(res, spec[1], 2);
}

void newf(char *str, int i, char *res, char **tab)
{
    char *base = tab[0];
    char *spec = tab[1];
    if (str[i] == spec[2]) {
        if (((i == 0) || !char_in_array(str[i - 1], base))
        && str[i - 1] != spec[1])
            custom_double_cat(res, base[0], spec[2]);
        else
            custom_triple_cat2(res, spec[1], spec[2], spec[0]);
    }
    if (str[i] == spec[3]) {
        if (((i == 0) || !char_in_array(str[i - 1], base))
        && str[i - 1] != spec[1])
            custom_double_cat(res, base[0], spec[3]);
        else
            custom_triple_cat2(res, spec[1], spec[3], spec[0]);
    }
    another_newf(str, i , res, spec);
}

char *modifstr(char *str, char *base, char *spec)
{
    char **tab = malloc(sizeof(char *) * 3);
    char *res = malloc(sizeof(char) * my_strlen(str) * 6);
    my_strxcat(res, spec[0], 3);
    char *c = malloc(sizeof(char) * 1);
    tab[0] = base;
    tab[1] = spec;
    for (int i = 0; str[i] != 0; i++) {
        newf(str, i, res, tab);
        if (str[i] != ' ' && str[i] != spec[2] && str[i] != spec[3] &&
            str[i] != spec[4] && str[i] != spec[5] && str[i] != spec[6] &&
            str[i] != '\n') {
                c[0] = str[i];
                my_strcat(res, c);
        }
    }
    free(c);
    my_strxcat(res, spec[1], 3);
    my_strcat(res, "\n");
    return res;
}