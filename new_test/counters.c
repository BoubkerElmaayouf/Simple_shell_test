#include "shell.h"

/**
  * count_input - Counts the words typed by the user
  * @new_str: The string that contains the words
  *
  * Return: The number of words found in the string
  */
int words_counter(char *new_str)
{
	int x = 0, stat = 0;
	int word_count = 0;
	while (new_str[x])
	{
		if (new_str[x] == '\n' || new_str[x] == ' ' ||  new_str[x] == '\t')
			stat = 0;
		else if (stat == 0)
		{
			stat = 1;
			word_count++;
		}
		x++;
	}
	return (word_count);
}

/**
  * count_delims - Counts delimiters in a string
  * @text: The string that contains the delimiters
  * @symbols: The delimiters to will find in the string
  *
  * Return: The number of delimiters in the string
  */
int symbols_counter(char *text, char *symbols)
{
	int x = 0, y = 0;
	int symbol_count = 0;

	while (symbols[x])
	{
		y = 0;
		while (text[y])
		{
			if (text[y] == symbols[x])
				symbol_count++;
			y++;
		}
		x++;
	}
	return (symbol_count);
}

