#include "shell.h"

/**
  * _print_env - Prints the environment built-in
  *
  * Return: Nothing to returns
  */
void display_env(void)
{
        int x, y;

        for (x = 0; _environ[x]; x++)
        {
                for (y = 0; _environ[x][y]; y++)
                {
                        _putchar(_environ[x][y]);
                }
                _putchar('\n');
        }
}
