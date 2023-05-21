#ifndef _SHELL_H
#define _SHELL_H

/******** Libraries **********/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

extern char **_environ;


/******** Prototypes *********/
/* ====== _exit.c =======*/
void _end_program(char **utkns, char *inputline);

/* ====== _getenv.c =======*/
char *_get_env(const char *var_name);

/* ====== open_help.c =======*/
void _help_me(void);

/* ====== print_env.c =======*/
void display_env(void);

/* ====== builtin_commands.c =======*/
int handleInputCmd(char **user_input, char *input_line);

/* ====== counters.c =======*/
int words_counter(char *new_str);
int symbols_counter(char *text, char *symbols);

/* ====== exec.c =======*/
char *path_concatination(char *n_path, char *n_prog);
char *find_cmd(char *cmd_name);
int _execve(char *command_name, char **arg);

/* ====== frees.c =======*/
void free_genv(char *environ_path);
void free_tkns(char **tokens);

/* ====== more_utilities.c =======*/
int _putchar(char chr);
void _printf(char *s);
int _strn_cmp(const char *string1, const char *string2, size_t _length);
void *_reallocation(void *ptr, unsigned int prev_size, unsigned int updated_size);

/* ====== utilities.c =======*/
char *_strcat(char *dest, char *src);
int _strlen(const char *str);
int _strcmp(char *s1, char *s2);
char *_strdup(char *origin_str);
int _atoi(char *nptr);

/* ====== more_new_line.c =======*/
char *chomp(char *str);

/* ====== signal_handler.c =======*/
void signal_func(int sig_num);
/* ====== _strtok.c =======*/
char *_strtok(char *strline, char *delim);
/* ====== tokenize.c =======*/
char **tokenizing(char *string, char *delim, int length);

#endif
