/*
** EPITECH PROJECT, 2019
** inf_mult.c
** File description:
** Infinit Mult
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "./include/my.h"

char *my_memset(char *s, char c, int n)
{
    for (int i = 0; i < n; i++) {
        s[i] = c;
    }
    return s;
}

char *inf_mult(char *nb1, char *nb2, char const *base)
{
    (void) base;
    int len_result = my_strlen(nb1) + my_strlen(nb2);
    char *result = malloc(sizeof(char)*(len_result + 1));
    int tmp = 0;
    int i;
    int j;

    if (!result)
        return (NULL);
    my_memset(result, '0', len_result);
    my_revstr(nb1);
    my_revstr(nb2);
    for (i = 0; nb1[i] != '\0'; i++) {
        for (j = 0; nb2[j] != '\0'; j++) {
            tmp = tmp + (nb1[i] - 48) * (nb2[j] - 48) + (result[i+j] - 48);
            printf("tmp = %d\n", tmp);
            result[i+j] = tmp%10 +48;
            tmp = tmp/10;
        }
    }
    if (tmp > 0) {
        result[i+j-1] = tmp + 48;
        result[i+j] = '\0';
    } else
        result[i+j-1] = '\0';
    my_revstr(result);
    return result;
}
