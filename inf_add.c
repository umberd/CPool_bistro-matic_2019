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

char *my_inf_add_two(char *s1, char * s2)
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

char *my_inf_add(char *str1, char *str2)
{
    char *result;
    int is_neg = 0;

    if (str1[0] == '\0' || str2[0] == '\0')
        return 84;
    if (str2[0] == '-' && str1[0] == '-') {
        is_neg = 1;
        result = my_inf_add(&str1[1], &str2[1]);
    }
    if (str2[0] == '-' && str1[0] != '-')
        result = inf_less(&str1[0], &str2[1], &is_neg);
    if (str2[0] != '-' && str1[0] == '-')
        result = inf_less(&str2[0], &str1[1], &is_neg);
    if (str2[0] != '-' && str1[0] != '-')
        result = inf_add(str1, str2);
    return my_putstr_l_z(result, is_neg);
}