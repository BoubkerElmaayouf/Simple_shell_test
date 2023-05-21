#include "shell.h"

/**
  * tokenizing - Extract tokens from string
  * @string: The string to tokenize
  * @delim: The delimiter of tokenization
  * @length: Tokens number
  *
  * Return: An array of tokens of the string
  */
char **tokenizing(char *string, char *delim, int length)
{
	char **array = NULL;
	char *element = NULL;
	char *temp_str = NULL;
	int i = 0;

	array = malloc(sizeof(char *) * (length + 1));
	if (!array)
		return (NULL);
	string = chomp(string);
	temp_str = _strdup(string);
	element = _strtok(temp_str, delim);

	while (element)
	{
		array[i] = _strdup(element);
		element = _strtok(NULL, delim);
		i++;
	}
	array[i] = NULL;
	free(temp_str);
	return (array);
}

