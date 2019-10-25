/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** No file there, just an epitech header example
*/

#include"include/my.h"
#include<stdio.h>
#include<stdlib.h>

int my_putstrnbr(char const *str);

int verif_alpha(char *s1, char *s2)
{
    int offset = 0;
    if (s1[offset] == '-')
        offset++;
    for (; s1[offset] != '\0'; offset++)
        if (s1[offset] < '0' || s1[offset] > '9')
            return 1;
    offset = 0;
    if (s2[offset] == '-')
        offset++;
    for (; s2[offset] != '\0'; offset++)
        if (s2[offset] < '0' || s2[offset] > '9')
            return 1;
    return 0;
}

char *infinite_add(char *s1, char * s2)
{
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);
    int lenmax = (len1 > len2) ? len1 : len2;
    int ret = 0;
    char *res = malloc (sizeof(char) * (lenmax + 1));
    res[lenmax + 1] = '\0';
    for (; lenmax > 0; len1--, len2--, lenmax--) {
        int op1 = (len1 <= 0) ? 0 : s1[len1 - 1] - 48;
        int op2 = (len2 <= 0) ? 0 : s2[len2 - 1] - 48;
        int temp = op1 + op2 + ret;
        res[lenmax] = (temp % 10) + 48;
        ret = temp / 10;
        res[0] = 2;
        if (ret != 0 && lenmax == 1)
            res[0] = 49;
    }
    return res;
}

char *infinite_sub(char *s1, char * s2)
{
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);
    int lenmax = (len1 > len2) ? len1 : len2;
    int ret = 0;
    char *res = malloc (sizeof(char) * (lenmax + 1));
    res[lenmax + 1] = '\0';
    for (; lenmax > 0; len1--, len2--, lenmax--) {
        int op1 = (len1 <= 0) ? 0 : s1[len1 - 1] - 48;
        int op2 = (len2 <= 0) ? 0 : s2[len2 - 1] - 48;
        int temp = op1 - op2 - ret;
        if (temp < 0) {
            temp = op1 + 10 - op2 - ret;
            ret = 1;
        }
        else
            ret = 0;
        res[lenmax] = (temp % 10) + 48;
        res[0] = 2;
    }
    return res;
}

void call_sub(char *argv[])
{
    if (argv[1][0] == '-') {
        if (my_strcmp(&argv[1][1], argv[2]) > 0) {
            my_putchar('-');
            my_putstrnbr(infinite_sub(&argv[1][1], argv[2]));
        }
        else if (my_strcmp(&argv[1][1], argv[2]) == 0)
            my_putchar('0');
        else
            my_putstrnbr(infinite_sub(argv[2], &argv[1][1]));
    }
    else {
        if (my_strcmp(&argv[2][1], argv[1]) > 0) {
            my_putchar('-');
            my_putstrnbr(infinite_sub(&argv[2][1], argv[1]));
        }
        else if (my_strcmp(&argv[2][1], argv[1]) == 0)
            my_putchar('0');
        else
            my_putstrnbr(infinite_sub(argv[1], &argv[2][1]));
    }
}
/*
int main(int argc, char *argv[])
{
    if (argc != 3 || verif_alpha(argv[1], argv[2]))
        return 84;
    if ((argv[1][0] == '-' || argv[2][0] == '-') && argv[1][0] != argv[2][0])
        call_sub(argv);
    else
        if (argv[1][0] == '-' && argv[2][0] == '-') {
            my_putchar('-');
            my_putstrnbr(infinite_add(&argv[1][1], &argv[2][1]));
        }
        else
            my_putstrnbr(infinite_add(argv[1], argv[2]));
    my_putchar('\n');
    return 0;
}*/