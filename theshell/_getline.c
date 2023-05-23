#include "shell.h"


int initialize_lineptr(char **lineptr, size_t *n)
{
    if (*lineptr == NULL) {
        *n = 128;
        *lineptr = (char*) malloc(*n * sizeof(char));
        if (*lineptr == NULL) {
            return -1;
        }
    }
    return 0;
}

/**
* _getline - this function mimics the builtin getline() function
* @lineptr: a double pointer of to the user input
* @n: the length of the input
* @stream: the file input stream
* Return: number characters on success, otherwise -1
*/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream) {
    char *new_ptr = NULL;
    static size_t x, y;
    char stream_char;

    if (initialize_lineptr(lineptr, n) == -1) {
        return -1;
    }

    x = 0;
    while (read(stream->_fileno, &stream_char, 1) == 1)
    {
        if (x >= *n - 1)
        {
            *n *= 2;
            new_ptr = (char *)malloc((*n) * sizeof(char));
            if (new_ptr == NULL)
                return (-1);

            y = 0;
            while (y < x)
            {
                new_ptr[y] = (*lineptr)[y];
                y++;
            }

            free(*lineptr);
            *lineptr = new_ptr;
        }
        (*lineptr)[x++] = stream_char;
        if (stream_char == '\n')
        {
            break;
        }
    }

    (*lineptr)[x] = '\0';
    if (x == 0 || stream_char == EOF)
        return (-1);
    else
        return (x);
}
