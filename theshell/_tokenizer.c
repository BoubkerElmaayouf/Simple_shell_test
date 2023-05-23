#include "shell.h"

/**
  * chomp - this function remove
  * @str: The string
  *
  * Return: The string without a new line character
  */
char *chomp(char *str)
{
	int x = 0;

	 for(; str[x]; x++)
    	{
        	if (str[x] == '\n')
            	str[x] = '\0';
    	}

	return (str);
}

/**
  * tokenizing - this function extract tokens from string
  * @string: The string to tokenize
  * @delim: The delimiter of tokenization
  * @length: The expected number of tokens.
  *
  * Return: an array of tokens extracted from the input string
  */
char **tokenizing(char *string, char *delim, int length)
{
    char **array = NULL;
    char *element = NULL;
    char *temp_str = NULL;
    int x;

    array = (char **) malloc((length + 1) * sizeof(char *));
    if (!array)
        return (NULL);
    string = chomp(string);
    temp_str = _strdup(string);
    element = _strtok(temp_str, delim);

    for (x = 0; element != NULL; x++)
    {
        array[x] = _strdup(element);
        element = _strtok(NULL, delim);
    }
    array[x] = NULL;
    free(temp_str);
    return (array);
}


