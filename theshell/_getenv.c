#include "shell.h"

/**
  * _get_env - this function gets an environment variable
  * @var_name: it's a pointer to a character
  * Return: what's in the environment variable
  */
char *_get_env(const char *var_name)
{
    char *envValue = NULL;
    int x = 0;
	
    for (; _environ[x]; ++x)
    {
        if (_strn_cmp(var_name, _environ[x], _strlen(var_name)) == 0)
        {
            envValue = _strdup(_environ[x]);
            while (*envValue != '=')
                envValue++;
            ++envValue;
            return (envValue);
        }
    }

    return (NULL);
}

