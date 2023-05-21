#include "shell.h"

/**
  * remove_new_line - Removes a new line character from string
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

