/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** No file there, just an epitech header example
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    for ( ; src[i] != '\0' && i < n; i++)
        dest[i] = src[i];
    for ( ; i < n; i++)
        dest[i] = '\0';
    return dest;
}