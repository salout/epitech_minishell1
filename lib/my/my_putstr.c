/*
** EPITECH PROJECT, 2017
** my_putstr.c
** File description:
** my_putstr.c
*/

void my_putchar(char);

int my_putstr(char const *str)
{
    for(int x = 0; str[x] != '\0'; x++)
        my_putchar(str[x]);
    return (0);
}
