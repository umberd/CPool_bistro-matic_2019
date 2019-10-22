/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** No file there, just an epitech header example
*/

void my_putchar(char c);

int my_putstrnbr(char const *str)
{
    int offset = 0;
    while (*(str + offset) <= '0') {// || *(str + offset) == 2) {
        if (*(str + offset) == '\0') {
            my_putchar('0');
            return (0);
        }
        offset++;
    }
    while (*(str + offset) != '\0') {
        char c = *(str + offset);
        my_putchar(c);
        offset += 1;
    }
    return (0);
}