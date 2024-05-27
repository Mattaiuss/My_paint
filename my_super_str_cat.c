/*
** EPITECH PROJECT, 2024
** my_super_str_cat
** File description:
** str_cat but nanoboosted
*/

#include "my.h"

int get_temp(int value, int *len_value)
{
    int temp_value = value;

    temp_value /= 10;
    while (temp_value > 0) {
        *len_value += 1;
        temp_value /= 10;
    }
    return value;
}

char *my_super_str_cat_int(char *string, int value, char *ext)
{
    int len_string = my_strlen(string);
    int len_value = 1;
    int len_ext = my_strlen(ext);
    char *result;

    get_temp(value, &len_value);
    result = malloc(sizeof(char) * (len_string + len_value + len_ext + 1));
    if (result == NULL)
        return NULL;
    for (int i = 0; i < len_string; i++)
        result[i] = string[i];
    for (int i = len_value - 1; i >= 0; i--) {
        result[len_string + i] = '0' + value % 10;
        value /= 10;
    }
    for (int i = 0; i < len_ext; i++)
        result[len_string + len_value + i] = ext[i];
    result[len_string + len_value + len_ext] = '\0';
    return result;
}
