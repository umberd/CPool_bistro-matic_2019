/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** No file there, just an epitech header example
*/
#include"include/my.h"
#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>

void another_newf(char *str, int i, char *res)
{
    if (str[i] == '*')
        my_strcat(res, ")*(");
    if (str[i] == '/')
        my_strcat(res, ")/(");
    if (str[i] == '%')
        my_strcat(res, ")\%(");
    if (str[i] == '(')
        my_strcat(res, "((");
    if (str[i] == ')')
        my_strcat(res, "))");
}

void newf(char *str, int i, char *res)
{
    if (str[i] == '+') {
        if (((i == 0) || (str[i - 1] < '0' ||
            str[i - 1] > '9')) && str[i - 1] != ')')
            my_strcat(res, "0+");
        else
            my_strcat(res, "))+((");
    }
    if (str[i] == '-') {
        if (((i == 0) || (str[i - 1] < '0' ||
            str[i - 1] > '9')) && str[i - 1] != ')')
            my_strcat(res, "0-");
        else
            my_strcat(res, "))-((");
    }
    another_newf(str, i , res);
}

char *modifstr(char *str)
{
    char *res = malloc(sizeof(char) * my_strlen(str) * 6 );
    my_strcat(res, "(((");
    char *c = malloc(sizeof(char) * 1);
    for (int i = 0; str[i] != 0; i++) {
        newf(str, i, res);
        if (str[i] != ' ' && str[i] != '+' && str[i] != '-' &&
            str[i] != '*' && str[i] != '/' && str[i] != '%' &&
            str[i] != '\n') {
                c[0] = str[i];
                my_strcat(res, c);
        }
    }
    free(c);
    my_strcat(res, ")))\n");
    return res;
}