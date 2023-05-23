#include "shell.h"

/**
 * print_prompt - This function prints a prompt to the user if the program is
 * running in an interactive shell.
 * Return : NOTHING
*/
void print_prompt()
{
    if (isatty(STDIN_FILENO))
        write(STDOUT_FILENO, "Dude$  ", 6);
}

/**
 * process_input - This function processes the input provided by the user.
 * @input_line: A pointer to the string containing the input entered by the user.
 * @inputLength: The length of the input string.
 * Return: NOTHING.
*/
void process_input(char* input_line, int inputLength)
{
    char** user_tokns = NULL;
    int cmdexec = 0;

    if (input_line[0] != '\n' && inputLength > 0)
    {
        user_tokns = tokenizing(input_line, " \t", inputLength);
        cmdexec = handleInputCmd(user_tokns, input_line);
        if (!cmdexec)
        {
            user_tokns[0] = find_cmd(user_tokns[0]);
            if (user_tokns[0] && access(user_tokns[0], X_OK) == 0)
                _execve(user_tokns[0], user_tokns);
            else
                perror("./hsh");
        }
        
        free_tkns(user_tokns);
    }
}
/**
 * main - this function work as link between the user and the shell program.
 *
 * Return : 0
 */
int main(void)
{
    char *input_line = NULL;
    ssize_t l_len = 0;
    size_t l_size = 0;
    int word_len;

    while (l_len >= 0)
    {
        signal(SIGINT, signal_func);
		/* displaying the promt before each input line.*/
        print_prompt();
        l_len = _getline(&input_line, &l_size, stdin);
        if (l_len == -1)
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            break;
        }

        word_len = words_counter(input_line);
		/**
 		 * checking for built-in commands or executable files, and executing
		 * the command if its possible.
 		 */
        process_input(input_line, word_len);
    }

    free(input_line);
    return 0;
}

