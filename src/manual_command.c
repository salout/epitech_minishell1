/*
** EPITECH PROJECT, 2017
** manual_command.c
** File description:
** project
*/

#include "my.h"

int do_unsetenv(char **env, char *buffer)
{
    int x;
    char **files;

    if ((x = count_word(buffer)) < 2) {
        my_putstr("unsetenv: Too few argument.\n");
        return (0);
    }
    files = my_str_to_word_array_spe(buffer);
    for (x = 1; files[x]; x++)
        modifie_env_unset(files[x], env);
    return (0);
}

int exec_bin(char *buffer)
{
    char **argument = my_str_to_word_array(buffer);
    pid_t child;
    int w;

    if (open(argument[0], O_RDONLY) == -1) {
        my_putstr(argument[0]);
        my_putstr(": Command not found.\n");
        return (0);
    }
    if ((child = fork()) == 0)
        execve(argument[0], argument, NULL);
    else if (child > 0)
        child = wait(&w);
    else
        kill(child, 0);
    if (WTERMSIG(w) == 11)
        my_putstr("Segmentation fault (core dumped)\n");
}

int do_setenv(char **env, char *buffer)
{
    int x;
    int c_env;
    int i = 0;
    int c_buf = 0;

    if ((x = count_word(buffer)) > 3) {
        my_putstr("setenv: Too many argument.\n");
        return (0);
    } else if (x == 1) {
        do_env("env\0", env);
        return (0);
    }
    for (; env[c_env] != NULL; c_env++);
    for (; buffer[c_buf - 1] != ' '; c_buf++);
    env[c_env] = malloc(sizeof (char) * my_strlen(buffer));
    for (; buffer[c_buf] != '\0'; c_buf++)
        env[c_env][i++] = buffer[c_buf] != ' ' ? buffer[c_buf] : '=';
    if (x == 2)
        env[c_env][i++] = '=';
    env[c_env][i] = '\0';
    env[++c_env] = NULL;
}

int do_cd(char *buffer, char **env)
{
    int x;
    int fd;
    char *path = malloc(sizeof (char) * my_strlen(buffer));

    if ((x = count_word(buffer)) > 2) {
        my_putstr("cd: Too many argument.\n");
        return (0);
    } else if (x == 1)
        path = "\0";
    else
        path = get_path_cd(buffer, path);
    if ((x = chdir(path)) == -1) {
        fd = open(path, O_RDONLY);
        my_putstr(path);
        if (fd == -1)
            my_putstr(": No such files or directory.\n");
        else
            my_putstr(": Not a directory.\n");
    } else
        modifie_env_cd(env);
}

void do_env(char *buffer, char **env)
{
    int x;

    if ((x = count_word(buffer)) != 1)
        my_putstr("env: To many argument.\n");
    else
        for(int i = 0; env[i] != NULL; i++) {
            my_putstr(env[i]);
            my_putchar('\n');
        }
}
