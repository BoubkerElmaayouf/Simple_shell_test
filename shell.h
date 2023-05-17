#ifndef _SHELL_H
#define _SHELL_H

/* libraries */
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

/* macors */
#define MAX_COMMANDS 10


/* prototypes */
char *_strtok(char *line, char *delim);
void _prompt(char **argv, char *env[]);


#endif
