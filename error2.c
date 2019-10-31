/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** Adding stuff together
*/

#include "include/my.h"

int print_error(void);

int check_dupe(char *str)
{
    for (int i = 0; i < my_strlen(str); i++)
        for (int j = 0; j < my_strlen(str); j++)
            if (str[i] == str[j] && i != j)
                return print_error();
    return 1;
}

int check_repetition(char *str1, char *str2)
{
    for (int i = 0; i < my_strlen(str1); i++)
        for (int j = 0; j < my_strlen(str2); j++)
            if (str1[i] == str2[j])
                return print_error();
    return 1;
}