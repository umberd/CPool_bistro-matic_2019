/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** No file there, just an epitech header example
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    if (nb < 0)
        return (0);

    if (nb < 3)
        return (2);

    for (int i = nb; ; i++) {
        if (my_is_prime(i))
            return (i);
    }
    return (0);
}