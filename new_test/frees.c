#include "shell.h"

/**
  * frees_get_env - ...
  * @environ_path: The environment variable to frees
  *
  * Return: Nothing to returns
  */
void free_genv(char *environ_path)
{
	int x = 4;

	for (; x >= 0; x--)
		environ_path--;

	free(environ_path);
}

/**
  * frees_tokens - ...
  * @tokens: ...
  *
  * Return: Nothing to returns
  */
void free_tkns(char **tokens)
{
	char **tokens_copy = tokens;

	if (tokens)
	{
		while (*tokens)
			free(*tokens++);

		free(tokens_copy);
	}
}
