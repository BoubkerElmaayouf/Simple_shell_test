#include "shell.h"

/**
  * path_concatination - this function concatonate a name to a path
  * @n_path: The path string
  * @n_prog: The program name string
  *
  * Return: The path name concatenated with the path
  */
char *path_concatination(char *n_path, char *n_prog)
{
	int path_length = 0, program_length = 0;
	int new_size = 0;

	program_length = _strlen(n_prog);
	path_length = _strlen(n_path);
	new_size = sizeof(char) * (path_length + program_length + 2);
	n_path = _reallocation(n_path, (path_length + 1), new_size);
	if (!n_path)
		return (NULL);

	_strcat(n_path, "/");
	_strcat(n_path, n_prog);

	return (n_path);
}

/**
  * find_cmd - this function verify if a command is found in the system
  * @cmd_name: the command name to be searched
  *
  * Return: The path name of the command or NULL if it failes
  */
char *find_cmd(char *cmd_name)
{
	char *environ_path = NULL;
	char **token_path = NULL;
	struct stat file_info;
	int delimiter_count = 0;
	int x = 0;

	if (cmd_name)
	{
		if (cmd_name[0] != '/' && stat(cmd_name, &file_info) != 0)
		{
			environ_path = _get_env("PATH");
			delimiter_count = symbols_counter(environ_path, ":") + 1;
			token_path = tokenizing(environ_path, ":", delimiter_count);

			while (token_path[x])
			{
				token_path[x] = path_concatination(token_path[x], cmd_name);

				if (stat(token_path[x], &file_info) == 0)
				{
					free(cmd_name);
					cmd_name = _strdup(token_path[x]);
					free_genv(environ_path);
					free_tkns(token_path);
					return (cmd_name);
				}
				x++;
			}
			free_genv(environ_path);
			free_tkns(token_path);
		}
		if (stat(cmd_name, &file_info) == 0)
			return (cmd_name);
	}
	free(cmd_name);
	return (NULL);
}

/**
  * _execve - this function executes a command
  * @command_name: variable that hold the command to be executed
  * @arg: flags and options of the command
  *
  * Return: a status value integer
  */
int _execve(char *command_name, char **arg)
{
    pid_t pid;
    int stat;

    pid = fork();
    if (pid == -1) {
        perror("fork failed");
        return (-1);
    }
    else if (pid == 0)
    {
        execve(command_name, arg, _environ);
    }
    else {
        do {
            waitpid(pid, &stat, WUNTRACED);
        } while (WIFEXITED(stat) == 0 && WIFSIGNALED(stat) == 0);
    }
    return (0);
}

