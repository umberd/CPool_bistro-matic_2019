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

int char_in_array(char c, char *str);

void my_strxcat(char *res, char c, int x)
{
    char *string = malloc(sizeof(char)*2);
    string[0] = c;
    for (int i = 0; i < x; i++)
        res = my_strcat(res, string);
}

void another_newf(char *str, int i, char *res, char *spec)
{
    if (str[i] == spec[4]) {
        my_strxcat(res, spec[1], 1);
        my_strxcat(res, spec[4], 1);
        my_strxcat(res, spec[0], 1);
    }
    if (str[i] == spec[5]) {
        my_strxcat(res, spec[1], 1);
        my_strxcat(res, spec[5], 1);
        my_strxcat(res, spec[0], 1);
    }
    if (str[i] == spec[6]) {
        my_strxcat(res, spec[1], 1);
        my_strxcat(res, spec[6], 1);
        my_strxcat(res, spec[0], 1);
    }
    if (str[i] == spec[0])
        my_strxcat(res, spec[0], 2);
    if (str[i] == spec[1])
        my_strxcat(res, spec[1], 2);
}

void newf(char *str, int i, char *res, char *base, char *spec)
{
    if (str[i] == spec[2]) {
        if (((i == 0) || !char_in_array(str[i - 1], base)) && str[i - 1] != spec[1]) {
            my_strxcat(res, base[0], 1);
            my_strxcat(res, spec[2], 1);
        }
        else {
            my_strxcat(res, spec[1], 2);
            my_strxcat(res, spec[2], 1);
            my_strxcat(res, spec[0], 2);
        }
    }
    if (str[i] == spec[3]) {
        if (((i == 0) || !char_in_array(str[i - 1], base)) && str[i - 1] != spec[1]) {
            my_strxcat(res, base[0], 1);
            my_strxcat(res, spec[3], 1);
        }
        else {
            my_strxcat(res, spec[1], 2);
            my_strxcat(res, spec[3], 1);
            my_strxcat(res, spec[0], 2);
        }
    }
    another_newf(str, i , res, spec);
}

char *modifstr(char *str, char *base, char *spec)
{
    char *res = malloc(sizeof(char) * my_strlen(str) * 6 );
    my_strxcat(res, spec[0], 3);
    char *c = malloc(sizeof(char) * 1);
    for (int i = 0; str[i] != 0; i++) {
        newf(str, i, res, base, spec);
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