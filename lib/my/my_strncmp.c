/*
** EPITECH PROJECT, 2017
** my_strncmp.c
** File description:
** my_strncmp.c
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int x = 0; x != n; x++)
        if (s1[x] != s2[x])
            return (0);
    return (1);
}
