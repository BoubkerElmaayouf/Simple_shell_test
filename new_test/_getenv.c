#include "shell.h"

/**
  * _getenv - Gets an environment variable
  * @var_name: The variable to find in the system environment
  *
  * Return: The content of the environment variable
  */
char *_get_env(const char *var_name)
{
	char *envValue = NULL;
	int x = 0;

	while (_environ[x])
	{
		if (_strn_cmp(var_name, _environ[x], _strlen(var_name)) == 0)
		{
			envValue = _strdup(_environ[x]);
			while (*envValue != '=')
				envValue++;
			++envValue;
			return (envValue);
		}
		x++;
	}
	return (NULL);
}

