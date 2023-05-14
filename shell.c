#include "shell.h"

/**
 * main - entry point for simple shell program
 * @argc: integer value representing the number of arguments passed to the program
 * @argv: array of strings containing command line arguments
 * @env: array of strings containing environment variables
 *
 * This function serves as the entry point for a simple shell program. If no command 
 * line arguments are provided, it calls the _prompt() function to display a prompt and 
 * execute commands entered by the user. The function returns 0 upon successful completion.
 */
int main(int argc, char *argv[], char **env)
{
    if (argc == 1)   
        _prompt(argv,env);  

    return 0;  
}
