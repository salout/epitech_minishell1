/*
** EPITECH PROJECT, 2017
** modifie_env.c
** File description:
** project
*/

#include "my.h"

void modifie_env_cd(char **env)
{
    int c_env = 0;
    int x = 4;
    char *cwd = NULL;
    char *temp;

    cwd = getcwd(cwd, 469);
    for (; my_strncmp(env[c_env], "PWD=", 4) != 1; c_env++);
    temp = malloc(sizeof (char) * my_strlen(env[c_env + 1]));
    temp = my_strcpy(temp, env[c_env + 1]);
    for (int i = 0; cwd[i] || cwd[i] == '\n'; i++)
        env[c_env][x++] = cwd[i];
    env[c_env][x--] = '\0';
    env[c_env + 1] = temp;
}

int modifie_env_unset(char *files, char **env)
{
    int line = -1;

    for (int x = 0; env[x]; x++)
        if (my_strncmp(env[x], files, my_strlen(files)) == 1)
            line = x;
    if (line == -1)
        return (0);
    else
        line++;
    for (; env[line]; line++)
        env[line - 1] = env[line];
    env[line - 1] = env[line];
}
