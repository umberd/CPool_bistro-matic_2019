/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** No file there, just an epitech header example
*/

int my_compute_power_rec(int nb, int p)
{
    if ( p < 0)
        return 0;

    if ( p != 0)
        return (nb * my_compute_power_rec(nb, p - 1));
    else
        return (1);
}