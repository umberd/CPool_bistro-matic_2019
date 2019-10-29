/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** No file there, just an epitech header example
*/

void my_sort_int_array(int *array, int size)
{
    int buffer;

    for (int point = 0; point < size - 1; point++) {
        if (array[point] > array[point+1]) {
            buffer = array[point];
            array[point] = array[point+1];
            array[point+1] = buffer;
            point = -1;
        }
    }
}