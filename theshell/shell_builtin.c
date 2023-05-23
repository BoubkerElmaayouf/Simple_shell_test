#include "shell.h"

int _strcmp(char *s1, char *s2);
void _end_program(char **utkns, char *inputline);
void display_env();

/**
 * _help_me - this function display a message when you entre help.
 *
 * Return: NOTIHNG
 */
void _help_me(void)
{
	_printf("\n****WELCOME TO WHERE YOU GONNA GET HELP****\n");
}

/**
 * handleInputCmd - this function handles built-in commands.
 * @user_input: an array of strings containing user input.
 * @input_line: a string containing the entire user input line.
 * Return: 1 if a built-in command was executed, 0 otherwise 
 */
int handleInputCmd(char **user_input, char *input_line)
{
        int x = 0;
        char *my_builtin_cmds[] = { "exit", "cd", "help", "env", NULL };

        while (my_builtin_cmds[x])
        {
                if (_strcmp(user_input[0], my_builtin_cmds[x]) == 0)
                {
                        if (x == 0) {
                                _end_program(user_input, input_line);
                                return (1);
                        }
                        else if (x == 1) {
                                chdir(user_input[1]);
                                return (1);
                        }
                        else if (x == 2) {
                                _help_me();
                                return (1);
                        }
                        else if (x == 3) {
                                display_env();
                                return (1);
                        }
                }
                x++;
        }

        return (0);
}

