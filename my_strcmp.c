/*
** EPITECH PROJECT, 2019
** CPool_rush1_2019
** File description:
** No file there, just an epitech header example
*/

int my_strcmp(char *str1, char *str2)
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i])
            return str1[i] - str2[i];
        i++;
    }
    return str1[i] - str2[i];
}