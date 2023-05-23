#include "shell.h"

/**
 * _putchar - this function write to stdout
 * @chr: The character to print
 *
 * Return: On success 1 and -1 on error
 */
int _putchar(char chr)
{
	return (write(1, &chr, 1));
}

/**
  * _printf - this function Prints a string
  * @s: The string to print
  *
  * Return: Nothing
  */
void _printf(char *s)
{
	int x = 0;
    for (; s[x] != '\0'; x++)
    {
        _putchar(s[x]);
    }
    _putchar('\n');
}

/**
  * _strn_cmp - this function Compares at most the first n bytes of string 1 and string 2
  * @string1: string
  * @string2: string
  * @_length: The limit of bytes for comparison
  *
  * Return: an integer value indicate the result of the comparison.
  */
int _strn_cmp(const char *string1, const char *string2, size_t _length)
{
	size_t current_pos = 0;

	for (; current_pos < _length; current_pos++)
	{
		if (string1[current_pos] != string2[current_pos])
		{
			return string1[current_pos] - string2[current_pos];
		}
	}

	return 0;
}
