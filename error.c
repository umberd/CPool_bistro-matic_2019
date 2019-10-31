/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** Adding stuff together
*/

#include "include/my.h"

int print_error(void)
{
    my_putstr("syntax error");
    return 0;
}

int base_include_test(char *str, char *base, char *spec)
{
    int check;
    for (int x = 0; str[x] != '\n'; x++) {
        check = 0;
        for (int i = 0; base[i] != '\0'; i++)
            if (base[i] == str[x])
                check = 1;
        for (int i = 0; spec[i] != '\0'; i++)
            if (spec[i] == str[x])
                check = 1;
        if (!check)
            return print_error();
    }
    return 1;
}

int char_in_array(char c, char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return 1;
    }
    return 0;
}

int cases_one(char *str, char *base, char *spec)
{
    int count1 = 0;
    int count2 = 0;

    for (int i = 0; str[i] != '\n'; i++) {
        if (char_in_array(str[i], base) && str[i+1] == spec[0])
            return print_error();
        if (char_in_array(str[i + 1], base) && str[i] == spec[1])
            return print_error();
        if (str[i] == spec[0])
            count1++;
        if (str[i] == spec[1])
            count2++;
    }
    if (count1 != count2)
        return print_error();
    return 1;
}

int error_test(char *str, char *base, char *spec)
{
    if (!base_include_test(str, base, spec))
        return 1;
    if (!cases_one(str, base, spec))
        return 1;
    return 0;
}