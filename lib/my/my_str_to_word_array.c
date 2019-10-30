/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** No file there, just an epitech header example
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int my_show_word_array(char * const *tab);

int my_strlen( char const *str);

int is_char_valid(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

void add_element(char **tab, char *str)
{
    int point = 0;
    for ( ; tab[point] != 0; point++);
    char *new_str = malloc(sizeof(char) * my_strlen(str));
    for (int i = 0; str[i] != '\0'; i++)
        new_str[i] = str[i];
    tab[point] = new_str;
    tab[point + 1] = 0;
}

char **my_str_to_word_array(char const *str)
{
    char **tab = malloc(sizeof(char *)*(my_strlen(str)));
    int point = 0;
    int point2 = 0;
    tab[0] = 0;
    char *word = malloc(sizeof(char)*my_strlen(str));

    while (str[point] != '\0') {
        for (point2 = 0; !is_char_valid(str[point])
        && str[point] != '\0'; point++);
        for ( ; is_char_valid(str[point]) ; point++) {
            word[point2] = str[point];
            point2++;
        }
        word[point2] = '\0';
        if (word[0] != '\0')
            add_element(tab, word);
        for ( int j = 0; word[j] != '\0'; word[j] = '\0', j++);
    }
    return tab;
}