/*
** EPITECH PROJECT, 2019
** tools.c
** File description:
** Cummon functions
*/

#include <unistd.h>
#include <stdlib.h>
#include "./include/my.h"

char *malloc_digit(char *to_copy, int i)
{
    char *result;

    result = malloc(sizeof(char) * (i + 2));
    if (to_copy != NULL) {
        my_strcpy(result, to_copy);
        free(to_copy);
    }
    return result;
}

char *my_putstr_l_z(char *result, int is_neg)
{
    char *neg;
    int len_result;

    for (;result[0] == '0'; result++);
    if (result[0] == '\0') {
        neg = malloc(sizeof(char) * 2);
        neg[0] = '0';
        neg[1] = '\0';
        return neg;
    } else if (is_neg == 1) {
        len_result = my_strlen(result);
        neg = malloc(sizeof(char) * (len_result + 2));
        neg[0] = '-';
        neg = my_strcat(neg, result);
        return neg;
    } else
        return result;
}