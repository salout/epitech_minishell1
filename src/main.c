/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** project
*/

#include "my.h"

void print_prompt(void)
{
    char *cwd = NULL;
    int i;

    cwd = getcwd(cwd, 100);
    i = my_strlen(cwd);
    for (; cwd[i] != '/'; i--);
    i++;
    for (; cwd[i] != '\0'; i++)
        my_putchar(cwd[i]);
    my_putstr(" $> ");
    free(cwd);
}

char **get_path(char **env, char *buffer)
{
    char **path = malloc(sizeof (char *) * 12);
    int c_env = 0;
    int x = 0;
    int c_path = 0;

    for (; my_strncmp(env[c_env], "PATH=", 5) != 1; c_env++);
    path[0] = malloc(sizeof (char) * my_strlen(buffer) + 25);
    for (int i = 5; env[c_env][i] != '\0'; i++) {
        if (env[c_env][i] != ':')
            path[c_path][x++] = env[c_env][i];
        else {
            path[c_path] = add_buff(path[c_path], x, buffer);
            x = 0;
            path[++c_path] = malloc(sizeof (char) * my_strlen(buffer) + 25);
        }
    }
    path[c_path] = add_buff(path[c_path], x, buffer);
    path[++c_path] = NULL;
    return (path);
}

int exec_command(char *buffer, char **env)
{
    char **path = get_path(env, buffer);
    char **argument = my_str_to_word_array(buffer);
    pid_t child;
    int w;

    for (int i = 0; path[i] != NULL; i++) {
        if (access(path[i], F_OK) == 0) {
            if ((child = fork()) == 0)
                execve(path[i], argument, NULL);
            else if (child > 0)
                child = wait(&w);
            else
                kill(child, 0);
            return (0);
        }
    }
    for (int i = 0; buffer[i] != ' ' && buffer[i]; i++)
        my_putchar(buffer[i]);
    my_putstr(": Command not found.\n");
    return (0);
}

char *clean_buffer(char *buffer)
{
    int c_buf = 0;
    int c_res = 0;
    char *res = malloc(sizeof (char) * my_strlen(buffer) + 1);

    for (int i = 0; buffer[i]; i++)
        if (buffer[i] == '\t')
            buffer[i] = ' ';
    for (; buffer[c_buf] == ' '; c_buf++);
    for (; buffer[c_buf] != '\0'; c_buf++) {
        if (buffer[c_buf] == ' ' && buffer[c_buf + 1] == ' ') {
            for (; buffer[c_buf] == ' ' && buffer[c_buf] != '\0'; c_buf++);
            c_buf--;
        }
        if (buffer[c_buf] != ' ' || buffer[c_buf + 1] != '\0')
            res[c_res++] = buffer[c_buf];
    }
    res[c_res] = '\0';
    free(buffer);
    return (res);
}

int main(int ac, char **av, char **env)
{
    char *buffer;
    size_t size;
    int x;

    print_prompt();
    x = getline(&buffer, &size, stdin);
    buffer[my_strlen(buffer) - 1] = '\0';
    while (my_strcmp(buffer, "exit") != 1) {
        if (x == -1)
            break ;
        buffer = clean_buffer(buffer);
        if (check_other_command(buffer, env) == 0)
            exec_command(buffer, env);
        print_prompt();
        x = getline(&buffer, &size, stdin);
        buffer[my_strlen(buffer) - 1] = '\0';
    }
    free(buffer);
    my_putstr("exit\n");
    return (0);
}
