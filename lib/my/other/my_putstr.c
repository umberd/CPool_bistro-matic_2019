/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** No file there, just an epitech header example
*/

#include <unistd.h>

void my_putchar(char c);

int my_putstr(char const *str)
{
    for (int point = 0; str[point] != '\0'; point++) {
        my_putchar(str[point]);
    }
    return (0);
}