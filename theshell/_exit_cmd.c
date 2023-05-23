#include "shell.h"

/**
  * _handle_exit - ...
  * @user_token: ...
  * @input_line: ...
  * Return: Nothing to returns
  */
void _end_program(char **user_token, char *input_line)
{
	int stat = 0;

	if (user_token[1] == NULL || (!_strcmp(user_token[1], "0")))
	{
		free_tkns(user_token);
		free(input_line);
		exit(0);
	}
	stat = _atoi(user_token[1]);
	if (stat != 0)
	{
		free_tkns(user_token);
		free(input_line);
		exit(stat);
	}
	else
	{
		_printf("exit: This Number Is Illegal : ");
		_printf(user_token[1]);
		_printf("\n");
		exit(2);
	}

	free_tkns(user_token);
	free(input_line);
	exit(EXIT_SUCCESS);
}

