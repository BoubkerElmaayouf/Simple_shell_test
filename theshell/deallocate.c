#include "shell.h"

/**
  * free_genv - this function frees the memory allocated
  * for the environment path.
  * @environ_path: pointer to the environment path.
  *
  * Return: Nothing 
  */
void free_genv(char *environ_path)
{
	int x = 4;

	for (; x >= 0; x--)
		environ_path--;

	free(environ_path);
}

/**
  * frees_tokens - this function frees the memory
  * allocated of an array of tokens
  * @tokens: it's a double pointer to the array
  *
  * Return: Nothing 
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

