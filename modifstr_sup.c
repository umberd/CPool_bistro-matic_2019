/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** No file there, just an epitech header example
*/

#include <stdlib.h>
#include "include/my.h"

void my_strxcat(char *res, char c, int x)
{
    char *string = malloc(sizeof(char)*2);
    string[0] = c;
    for (int i = 0; i < x; i++)
        res = my_strcat(res, string);
}

void custom_triple_cat(char *res, char a, char b, char c)
{
    my_strxcat(res, a, 1);
    my_strxcat(res, b, 1);
    my_strxcat(res, c, 1);
}

void custom_triple_cat2(char *res, char a, char b, char c)
{
    my_strxcat(res, a, 2);
    my_strxcat(res, b, 1);
    my_strxcat(res, c, 2);
}

void custom_double_cat(char *res, char a, char b)
{
    my_strxcat(res, a, 1);
    my_strxcat(res, b, 1);
}