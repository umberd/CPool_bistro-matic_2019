/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** No file there, just an epitech header example
*/

int custom_length(char const *str, int point)
{
    int length = 0;
    for (; str[point] != '\0' && str[point] >= '0' 
    && str[point] <= '9'; point++)
        length++;
    return (length);
}

int check_too_long(char const *str, int point, int sign)
{
    int breaker = 0;
    char str_max[10] = "2147483647";

    if (custom_length(str,point) > 11)
        return (0);

    if (sign == -1)
        str_max[9] = '8';

    if ( custom_length(str,point) == 10) {
        for (int i = 0; i < 10 && breaker != 1; i++) {
            if (str[i+point] > str_max[i])
                return (0);
            else if (str[i+point] < str_max[i])
                breaker = 1;
        }
    }
    return (1);
}

int my_getnbr(char const *str)
{
    int point = 0;
    int sign = 1;
    int result = 0;

    for (; str[point] == '-' || str[point] == '+'; point++) {
        if (str[point] == '-')
            sign = sign * -1;
    }

    if (!check_too_long(str,point,sign))
        return (0);

    for (; str[point] != '\0' && str[point] >= '0' 
    && str[point] <= '9'; point++) {
        result = result * 10;
        result += (str[point] - 48);
    }
    return (sign * result);
}