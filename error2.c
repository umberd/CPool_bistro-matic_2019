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
    for (int i = 0; i < my_strlen(str); i++) {
        for (int j = 0; j < my_strlen(str); j++) {
            if (str[i] == str[j] && i != j) {
                my_putstr("Problem with -> ");
                my_putstr(str);
                my_putchar('\n');
                return print_error();
            }
        }
    }
    return 1;
}