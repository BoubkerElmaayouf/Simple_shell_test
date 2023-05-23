#include "shell.h"

/**
  * signal_func - this function is a signal handler for sigint
  * @sig_num: received number 
  *
  * Return: NOTHING
  */
void signal_func(int sig_num)
{
	if (sig_num == SIGINT)
		write(STDOUT_FILENO, "\n$ ", 3);
}
