#include "shell.h"
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
