/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** No file there, just an epitech header example
*/

int my_is_prime(int nb)
{
    if (nb < 2 || nb == 4)
        return (0);

    for (int i = 2; i < nb/2; i++) {
        if ((nb%i) == 0)
            return (0);
    }
    return (1);
}