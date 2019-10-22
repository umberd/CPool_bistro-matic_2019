/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** No file there, just an epitech header example
*/

void my_swap(int *a, int *b)
{
    int buffer;
    buffer = *a;
    *a = *b;
    *b = buffer;
}