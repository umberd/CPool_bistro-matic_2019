/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** Adding stuff together
*/

#include "include/my.h"

char *inf_mult(char *nb1, char *nb2, char const *base);

int main(int argc, char **argv)
{
    if (argc > 1)
        my_putstr(inf_mult(argv[1],argv[2],argv[3]));
    return 0;
}