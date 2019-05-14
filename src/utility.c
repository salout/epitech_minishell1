/*
** EPITECH PROJECT, 2017
** utility.c
** File description:
** project
*/

#include "my.h"

int count_word(char *buffer)
{
    int res = 0;

    for (int i = 0; buffer[i]; i++)
        if (buffer[i] == ' ')
            res++;
    return (res + 1);
}

char *get_path_cd(char *buffer, char *path)
{
    int c_buf = 0;
    int c_path = 0;

    for (; buffer[c_buf] != ' '; c_buf++);
    c_buf++;
    for (; buffer[c_buf]; c_buf++)
        path[c_path++] = buffer[c_buf];
    path[c_path] = '\0';
    return (path);
}

int check_next_command(char *buffer, char **env)
{
    if (my_strncmp(buffer, "setenv ", 7) == 1 || \
    my_strcmp(buffer, "setenv") == 1) {
        do_setenv(env, buffer);
        return (1);
    } else if (my_strncmp(buffer, "unsetenv ", 9) == 1 || my_strcmp(buffer, \
    "unsetenv") == 1) {
        do_unsetenv(env, buffer);
        return (1);
    } else if (buffer[0] == '.' && buffer[1] == '/') {
        exec_bin(buffer);
        return (1);
    }
    return (0);
}

int check_other_command(char *buffer, char **env)
{
    if (my_strncmp(buffer, "cd ", 3) == 1 || my_strcmp(buffer, "cd") == 1) {
        do_cd(buffer, env);
        return (1);
    } else if (my_strncmp(buffer, "env ", 4) == 1 || my_strcmp(buffer, "env") \
    == 1) {
        do_env(buffer, env);
        return (1);
    } else
        return (check_next_command(buffer, env));
}

char *add_buff(char *path, int x, char *buffer)
{
    path[x++] = '/';
    for (int i = 0; buffer[i] != '\0' && buffer[i] != ' '; i++)
        path[x++] = buffer[i];
    return (path);
}
