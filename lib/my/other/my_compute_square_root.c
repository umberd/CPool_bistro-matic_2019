/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** No file there, just an epitech header example
*/

int my_compute_square_root(int nb)
{
    if (nb < 0)
        return (0);

    for (int i = nb; i > 0; i--)
        if (i*i == nb)
            return i;

    return (0);
}