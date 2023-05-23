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

#define BUFFER_SIZE 4096

extern char **_environ, buffer[BUFFER_SIZE];

/******** Prototypes *********/
/* ====== _exit_cmd.c=======*/
void _end_program(char **utkns, char *inputline);

/* ====== _getenv.c =======*/
char *_get_env(const char *var_name);

/* ====== _getline.c =======*/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

/* ====== display_env.c =======*/
void display_env(void);

/* ====== shell_builtin.c=======*/
void _help_me(void);
int handleInputCmd(char **user_input, char *input_line);

/* ====== _counters.c =======*/
int symbols_counter(char *text, char *symbols);
int words_counter(char *new_str);

/* ====== exec_func.c=======*/
char *path_concatination(char *n_path, char *n_prog);
char *find_cmd(char *cmd_name);
int _execve(char *command_name, char **arg);

/* ====== deallocate.c=======*/
void free_genv(char *environ_path);
void free_tkns(char **tokens);

/* ====== extra_tools.c =======*/
int _putchar(char chr);
void _printf(char *s);
int _strn_cmp(const char *string1, const char *string2, size_t _length);

/* ====== str_manipulation.c  =======*/
char *_strcat(char *dest, char *src);
int _strlen(const char *str);
int _strcmp(char *s1, char *s2);
char *_strdup(char *origin_str);
char *_strtok(char *strline, char *delim);


/* ====== signal_func.c=======*/
void signal_func(int sig_num);

/* ====== tools.c =======*/
int _atoi(char *nptr);
void *_reallocation(void *ptr, unsigned int prev_size, unsigned int updated_size);

/* ====== _tokenizer.c=======*/
char **tokenizing(char *string, char *delim, int length);
char *chomp(char *str);

#endif

