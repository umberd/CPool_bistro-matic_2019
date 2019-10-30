/*
** EPITECH PROJECT, 2019
** check_zero.c
** File description:
** Infinit Mult
*/

char *my_putstr_l_z(char *result, int is_neg);
char *inf_mult(char *nb1, char *nb2, char const *base);
char *inf_div(char *nb1, char *nb2, char const *base);
char *inf_mod(char *nb1, char *nb2, char const *base);

char *inf_mult_verif(char *nb1, char *nb2, char *base, char *spec)
{
    if (nb1[0] == spec[3] && nb2[0] == spec[3])
        return inf_mult(&nb1[1], &nb2[1], base);
    if (nb1[0] == spec[3] && nb2[0] != spec[3])
        return my_putstr_l_z(inf_mult(&nb1[1], nb2, base), 1);
    if (nb1[0] != spec[3] && nb2[0] == spec[3])
        return my_putstr_l_z(inf_mult(nb1, &nb2[1], base), 1);
    if (nb1[0] != spec[3] && nb2[0] != spec[3])
        return inf_mult(nb1, nb2, base);
}

char *inf_div_verif(char *nb1, char *nb2, char *base, char *spec)
{
    if (nb1[0] == spec[3] && nb2[0] == spec[3])
        return inf_div(&nb1[1], &nb2[1], base);
    if (nb1[0] == spec[3] && nb2[0] != spec[3])
        return my_putstr_l_z(inf_div(&nb1[1], nb2, base), 1);
    if (nb1[0] != spec[3] && nb2[0] == spec[3])
        return my_putstr_l_z(inf_div(nb1, &nb2[1], base), 1);
    if (nb1[0] != spec[3] && nb2[0] != spec[3])
        return inf_div(nb1, nb2, base);
}

char *inf_mod_verif(char *nb1, char *nb2, char *base, char *spec)
{
    if (nb1[0] == spec[3] && nb2[0] == spec[3])
        return my_putstr_l_z(inf_mod(&nb1[1], &nb2[1], base), 1);
    if (nb1[0] == spec[3] && nb2[0] != spec[3])
        return my_putstr_l_z(inf_mod(&nb1[1], nb2, base), 1);
    if (nb1[0] != spec[3] && nb2[0] == spec[3])
        return inf_mod(nb1, &nb2[1], base);
    if (nb1[0] != spec[3] && nb2[0] != spec[3])
        return inf_mod(nb1, nb2, base);
}