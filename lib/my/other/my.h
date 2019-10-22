/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** No file there, just an epitech header example
*/

int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_is_prime(int nb);
int my_isneg(int n);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);
void my_sort_int_array(int *array, int size);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char *str1, char *str2);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strncpy(char *dest, char const *src, int n);
void my_swap(int *a, int *b);
int my_show_word_array(char * const *tab);
char **my_str_to_word_array(char const *str);
char *my_strdup(char const *src);

//CUSTOM FUNCTIONS

int custom_length(char const *str, int point);
int check_too_long(char const *str, int point, int sign);
void hardcoded_case(void);
int initial_cases(int nb);
int is_char_valid(char c);
void add_element(char **tab, char *str);