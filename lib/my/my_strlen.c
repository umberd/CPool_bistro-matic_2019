/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** No file there, just an epitech header example
*/

int my_strlen( char const *str)
{
    int point;
    for (point = 0; str[point] != '\0'; point++);
    return (point);
}