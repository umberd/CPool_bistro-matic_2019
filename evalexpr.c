/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** No file there, just an epitech header example
*/
#include"include/my.h"
#include "include/my_inf_add.h"
#include<unistd.h>
#include<stdlib.h>

char *inf_mult_verif(char *nb1, char *nb2, char const *bs, char *);

char *inf_mod_verif(char *a, char *b, char *bs, char *);

char *inf_div_verif(char *a, char *b, char *bs, char *);

char *modifstr(char *str);

int char_in_array(char c, char *str);

char  *my_strtol(char **str, char *base)
{
    char *str_num = malloc(sizeof(char)*my_strlen(str[0]));
    int i = 0;
    int j = 0;
    for (; !char_in_array(str[0][i], base) && str[0][i] != 0; i++);
    for (; str[0][i] != 0 && char_in_array(str[0][i], base); i++, j++)
        str_num[j] = str[0][i];
    str[0] = &str[0][i];
    return str_num;
}

char *remove_par(char **s, int i, char *spec)
{
    char *str = *s;
    int par = 0;
    int x = i + 1;
    for (; str[x] != spec[1] || par != 0; x++){
        if (str[x] == spec[0])
            par += 1;
        if (str[x] == spec[1])
            par -= 1;
    }
    char *str1 = malloc(sizeof(char) * x - 1 - i);
    for (int j = 0; j < my_strlen(str1); j++)
        str1[j] = 0;
    my_strncpy(str1, str + i + 1, x - 1 - i);
    *s = &str[x - 1];
    return str1;
}

char *eval_expr(char const *s, char *base, char *spec);

char *operation(char **str, int verifzero, char *base, char *spec)
{
    int i = 0;
    char *s = *str;
    char *res;
    if (s[i + 1] == spec[0])
        res = eval_expr(remove_par(str, 1, spec), base, spec);
    else
        res = my_strtol(str, base);
    if (verifzero && res[0] == base[0]) {
        write(2, "syntax error", 12);
        exit(84);
    }
    else
        return res;
}

char *eval_expr(char const *s, char *bs, char *sp)
{
    char *str = my_strdup(s);
    char *res = my_strtol(&str, bs);
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == sp[2])
            res = inf_add(res, operation(&str, 0, bs, sp));
        if (str[i] == sp[3])
            res = inf_sub(res, operation(&str, 0, bs, sp));
        if (str[i] == sp[4])
            res = inf_mult_verif(res, operation(&str, 0, bs, sp), bs, sp);
        if (str[i] == sp[5])
            res = inf_div_verif(res, operation(&str, 1, bs, sp), bs, sp);
        if (str[i] == sp[6])
            res = inf_mod_verif(res, operation(&str, 1, bs, sp), bs, sp);
        if (str[i] != sp[2] && str[i] != sp[3] &&
            str[i] != sp[4] && str[i] != sp[5] && str[i] != sp[6])
            str = str + 1;
    }
    return res;
}