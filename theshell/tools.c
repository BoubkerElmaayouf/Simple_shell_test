#include "shell.h"
/**
  * _atoi - this function convert a string to an integer.
  * @s: the pointer string to convert
  *
  * Return: an integer
  */
int _atoi(char *s)
{
	int is_negative = 0;
	int is_degit = 1;
	int index = 0;
	unsigned int number = 0;

	while (s[index])
	{
		if (s[index] == '-')
			is_degit *= -1;

		while (s[index] >= '0' && s[index] <= '9')
		{
			is_negative = 1;
			number = (number * 10) + (s[index] - '0');
			index++;
		}

		if (is_negative == 1)
			break;

		index++;
	}

	number *= is_degit;
	return (number);
}

/**
  * _reallocation - this function resizes the memory block previously allocated
  * @ptr: pointer to the memory block allocated before
  * @prev_size: the previous size
  * @updated_size: the updated size
  *
  * Return: a pointer to the resized memory block
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

	while (x < prev_size && x < updated_size)
    {
        new_ptr[x] = ((char *) ptr)[x];
        x++;
    }

	free(ptr);
	return (new_ptr);
}

