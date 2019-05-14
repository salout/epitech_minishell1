/*
** EPITECH PROJECT, 2017
** my_strcmp.c
** File description:
** my_strcmp.c
*/

int my_strlen(char *);

int my_strcmp(char *s1, char *s2)
{
    if (my_strlen(s1) != my_strlen(s2))
        return (0);
    for (int x = 0; s1[x] != '\0' && s2[x] != '\0'; x++)
        if (s1[x] != s2[x])
            return (0);
    return (1);
}
