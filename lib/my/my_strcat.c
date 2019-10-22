/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** No file there, just an epitech header example
*/

char *my_strcat(char *dest, char const *src)
{
    int i;
    int j;
    for ( i = 0; dest[i] != '\0'; i++);
    for ( j = 0; src[j] != '\0'; i++, j++)
        dest[i] = src[j];
    dest[i] = '\0';
    return dest;
}