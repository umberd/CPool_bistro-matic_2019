/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** No file there, just an epitech header example
*/

#include <stdlib.h>

int my_strlen( char const *str);

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *result = malloc(sizeof(char)*(len + 1));
    for ( int i = 0; src [i] != '\0'; i++) {
        result[i] = src[i];
    }
    result[len] = '\0';
    return result;
}