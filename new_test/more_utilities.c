#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @chr: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char chr)
{
	return (write(1, &chr, 1));
}

/**
  * _puts - Prints a string
  * @str: The string to print
  *
  * Return: Nothing to returns
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
  * _strncmp - Compares at most the first n bytes of str1 and str2
  * @string1: The first string
  * @string2: The second string
  * @_length: The limit bytes of comparison
  *
  * Return: int value
  */
int _strn_cmp(const char *string1, const char *string2, size_t _length)
{
	unsigned int current_pos = 0;
	int result = 0;

	while (current_pos < _length)
	{
		if (string1[current_pos] == string2[current_pos])
		{
			current_pos++;
			continue;
		}
		else
		{
			result = string1[current_pos] - string2[current_pos];
			break;
		}

		current_pos++;
	}

	return (result);
}

/**
  * _reallocation - Resize the ptr that was previously allocated
  * @ptr: The pointer previously allocated
  * @prev_size: The old size of the pointer
  * @updated_size: The new size of the new pointer
  *
  * Return: A new pointer to the memory block allocated with the new size
  */
void *_reallocation(void *ptr, unsigned int prev_size, unsigned int updated_size)
{
	unsigned int x = 0;
	char *new_ptr;

	if (updated_size == prev_size)
		return (ptr);

	if (ptr == NULL)
	{
		new_ptr = malloc(updated_size);

		if (new_ptr == NULL)
			return (NULL);

		return (new_ptr);
	}
	else
	{
		if (updated_size == 0)
		{
			free(ptr);
			return (NULL);
		}
	}
	new_ptr = malloc(updated_size);

	if (new_ptr == NULL)
		return (NULL);

	for (; x < prev_size && x < updated_size; x++)
	{
		new_ptr[x] = ((char *) ptr)[x];
	}

	free(ptr);
	return (new_ptr);
}

