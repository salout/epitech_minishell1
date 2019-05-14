/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** my.h
*/

#ifndef _MY_H_
#define _MY_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>

void my_putchar(char);
int my_putstr(char const *);
int my_strcmp(char const *, char const *);
char *my_strcpy (char *, char const *);
int my_strlen(char const *);
int my_strncmp(char const *, char const *, int);
char **my_str_to_word_array(char const *);
char *add_buff(char *, int, char *);
int check_other_command(char *, char **);
int do_cd(char *, char **);
int count_word(char *);
char *get_path_cd(char *, char *);
void do_env(char *, char **);
int do_setenv(char **, char *);
int do_unsetenv(char **, char *);
void modifie_env_cd(char **);
int modifie_env_unset(char *, char **);
int exec_bin(char *);
char **my_str_to_word_array_spe(char const *);

#endif
