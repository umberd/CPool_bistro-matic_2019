/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** No file there, just an epitech header example
*/

#include <unistd.h>

void my_putchar(char c);

void hardcoded_case(void)
{
    my_putchar('-');
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('8');
}

int initial_cases(int nb)
{
    if (nb == 0)
        my_putchar('0');
    if (nb == -2147483648) {
        hardcoded_case();
        return (0);
    }
    if (nb < 0 ) {
        my_putchar('-');
        nb = nb * -1;
    }
    return nb;
}

int power(int i, int counter)
{
    int pow_result = 1;
    for (int y = i; y < counter - 1; y++ )
            pow_result = pow_result * 10;
    return pow_result;
}

int my_put_nbr(int nb)
{
    int counter = 0;
    int pow_result = 1;

    nb = initial_cases(nb);

    int buffer = nb;

    if (nb == 0 )
        return (0);

    for (; buffer != 0 ; counter++)
        buffer /= 10;

    for (int i = 0 ; i < counter; i++ ) {
        pow_result = power(i,counter);
        buffer = nb / pow_result;
        nb = nb - buffer * pow_result;
        my_putchar(buffer+48);
    }
    return (0);
}