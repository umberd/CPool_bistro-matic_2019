/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** No file there, just an epitech header example
*/

char *my_revstr(char *src)
{
    char buffer;
    int length;

    for (length = 0; src[length] != '\0'; length++);
    for (int i = 0; i < length / 2; i++) {
        buffer = src[i];
        src[i] = src[length - i - 1];
        src[length - i - 1] = buffer;
    }
    return src;
}