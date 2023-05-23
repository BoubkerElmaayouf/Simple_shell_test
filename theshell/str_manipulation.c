#include "shell.h"



/**
  * _strlen - this function counts the length of a string
  * @s: it hold the string to be counted
  *
  * Return: The length
  */
int _strlen(const char *s)
{
        int x = 0;

        while (s[x])
                x++;

        return (x);
}

/**
  * _strcmp - this function compares two strings
  * @s1: a string
  * @s2: a string
  *
  * Return: an int
  */
int _strcmp(char *s1, char *s2)
{
    int s1_len = 0, s2_len = 0;
    int difference = 0, limit = 0;
    int index = 0;

    s1_len = _strlen(s1);
    s2_len = _strlen(s2);

    if (s1_len <= s2_len)
        limit = s1_len;
    else
        limit = s2_len;

    for (; index <= limit; index++)
    {
        if (s1[index] == s2[index])
            continue;

        difference = s1[index] - s2[index];
        break;
    }

    return difference;
}

/**
  * _strcat - this function gather two strings
  * @dest: a pointer string destination 
  * @src: a pointer to source of string
  * Return: A pointer to the resulting string
  */
char *_strcat(char *dest, char *src)
{
    int dest_len = 0;
    int x = 0;

    while (dest[dest_len])
        dest_len++;

    x = 0;
    while (src[x] != '\0')
    {
        dest[dest_len] = src[x];
        dest_len++;
        x++;
    }

    dest[dest_len] = '\0';
    return (dest);
}

/**
 * _strtok - this function separates the strings with delimiters
 * @strline: A pointer to array that we had received in getline.
 * @delim: A characters we mark off string in parts.
 * Return: A pointer to the created token
*/
char *_strtok(char *strline, char *delim)
{
	static char *strp;
	char *stringcopy;
	int i;

	if (strline != NULL)
		strp = strline;
	for (; *strp != '\0'; strp++)
	{
		for (i = 0; delim[i] != '\0'; i++)
		{
			if (*strp == delim[i])
			break;
		}
		if (delim[i] == '\0')
			break;
	}
	stringcopy = strp;
	if (*stringcopy == '\0')
		return (NULL);
	for (; *strp != '\0'; strp++)
	{
		for (i = 0; delim[i] != '\0'; i++)
		{
			if (*strp == delim[i])
			{
				*strp = '\0';
				strp++;
				return (stringcopy);
			}
		}
	}
	return (stringcopy);
}

/**
  * _strdup - this function duplicate
  * @str: a string
  *
  * Return: the duplicated string
  */
char *_strdup(char *str)
{
	int length = 1;
	char *new_str;
	int x = 0;

	if (str == NULL)
		return (NULL);

	length = _strlen(str);
	new_str = malloc((sizeof(char) * length) + 1);
	if (new_str == NULL)
		return (NULL);

	for (; x < length; x++)
	{
		new_str[x] = str[x];
	}

	new_str[length] = '\0';
	return (new_str);
}

