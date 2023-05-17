#include "shell.h"

/**
 * _isatty - verifie if standard input is a terminal.
 * Return: NOTHING
*/
void _isatty(void)
{
	if (isatty(STDIN_FILENO))
        write(1, "$ ", 2);
}

void _prompt(char **argv, char *env[])
{
char *strptr = NULL;
pid_t pid;
ssize_t char_len;
int stat, i,j;
size_t n = 0;
char *argvptr[MAX_COMMANDS];
char *delim = " ";
int infinity = 1;

while (infinity)
{
    _isatty();
    char_len = getline(&strptr, &n, stdin);
    if(char_len == -1)
    {
        free(strptr);
        exit(EXIT_FAILURE);
    }
    
    i = 0;
    for (;strptr[i]; i++)
    {
        if(strptr[i] == '\n')
            strptr[i] = 0;
    }

    exitshell(EXIT_SUCCESS, strptr);
    j = 0;
    argvptr[j] = _strtok(strptr, delim);
    while (argvptr[j] != NULL)
    {
        j++;
        argvptr[j] = _strtok(NULL, delim);
    }

    pid = fork();
    if (pid == -1)
    {
        free(strptr);
        exit(EXIT_FAILURE);
    }
    if (pid == 0)
    {
        int val = execve(argvptr[0], argvptr, env);
        if (val < 0)
        {
              perror(argv[0]);
        }
    }
   else
   {
      wait(&stat);
   }
}
}
