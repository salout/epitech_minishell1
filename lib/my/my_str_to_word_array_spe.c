/*
** EPITECH PROJECT, 2017
** my_str_to_word_array_spe.c
** File description:
** my_str_to_word_array_spe
*/

#include <stdlib.h>

int count_space_spe(char const *str)
{
    int a = 0;
    int i = 0;

    for (int x = 0; str[x] != '\0'; x++) {
        if (str[x] == ' ' && a == 0) {
            a = 1;
            i++;
        } else if (str[x] != ' ' && a == 1)
            a = 0;
    }
    return (i + 1);
}

char **my_str_to_word_array_spe(char const *str)
{
    int y = 0;
    int a = 0;
    char **temp = malloc(sizeof (char * ) * count_space_spe(str));

    temp[y] = malloc(sizeof (char *) * 1);
    for (int x = 0; str[x] != '\0'; x++) {
        if (str[x] == ' ' && a == 0)
            a = 0;
        else if (str[x] != ' ')
            temp[y][a++] = str[x];
        else {
            temp[y][a++] = '=';
            temp[y][a] = '\0';
            temp[++y] = malloc(sizeof (char *) * 1);
            a = 0;
        }
    }
    temp[y][a++] = '=';
    temp[y][a] = '\0';
    temp[++y] = NULL;
    return (temp);
}
