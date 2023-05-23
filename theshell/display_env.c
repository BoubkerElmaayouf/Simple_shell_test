#include "shell.h"

/**
  * display_env - this function Print the current environment.
  *
  * Return: NOTIHNG
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

