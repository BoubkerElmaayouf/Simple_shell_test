#include "shell.h"

/**
  * symbols_counter - this function count how many time a special symbol occur
  * @text: The input text.
  * @symbols: it contain the symbols to count.
  *
  * Return: The number of symbols
  */
int symbols_counter(char *text, char *symbols)
{
        int x = 0;
        int y = 0;
        int symbol_count = 0;

    for (; symbols[x]; x++)
    {
        for (y = 0; text[y]; y++)
        {
            if (text[y] == symbols[x])
            {
                symbol_count++;
            }
        }
    }
    return (symbol_count);
}

/**
  * words_counter - this function counts the words
  * @new_str: it contain the words.
  *
  * Return: the total number of the words.
  */
int words_counter(char *new_str)
{
    int word_count = 0;
    int stat = 0;
    int x;

    for (x = 0; new_str[x] != '\0'; x++)
    {
        if (new_str[x] == '\n' || new_str[x] == ' ' || new_str[x] == '\t')
        {
            stat = 0;
        }
        else if (stat == 0)
        {
            stat = 1;
            word_count++;
        }
    }

    return (word_count);
}

