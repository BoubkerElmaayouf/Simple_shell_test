#include "shell.h"

/**
  * signal_handler - Handles the signals
  * @sig_num: The identifier of the signal to handle
  *
  * Return: Nothing to returns
  */
void signal_func(int sig_num)
{
	if (sig_num == SIGINT)
		write(STDOUT_FILENO, "\n$ ", 3);
}
