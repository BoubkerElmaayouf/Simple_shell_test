#include "shell.h"

void exitshell(int n, char *input)
{
input[strcspn(input, "\n")] = 0;
if (strcmp(input, "exit") == 0)
{
    exit(n);
}
}
