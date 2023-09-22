#include "main.h"

/**
 * _getline - This function is responsible for reading and processing input data
 *            to prepare commands for execution within a shell program.
 *
 * @data: A pointer to an "about" structure, which holds program state and configuration.
 *
 * Return: The function returns the number of characters in the line read or -1
 *         if there is no more input data to read.
 */


int _getline(allInfo *data)
{
	char buff[BUFFER_SIZE] = {'\0'};
	static char *arrayCommands[10] = {NULL};
	static char arrayOperators[10] = {'\0'};
	ssize_t bytesRead;
	int i = 0;

	if (!arrayCommands[0] || (arrayOperators[0] == '&' && errno != 0) ||
		(arrayOperators[0] == '|' && errno == 0))
	{
		for (i = 0; arrayCommands[i]; i++)
		{
			free(arrayCommands[i]);
			arrayCommands[i] = NULL;
		}
		bytesRead = read(data->file_desc, &buff, BUFFER_SIZE - 1);
		if (bytesRead == 0)
			return (-1);

		i = 0;
		do {
			arrayCommands[i] = string_repetitions(str_tok(i ? NULL : buff, "\n;"));
			i = logical_operations(arrayCommands, i, arrayOperators);
		} while (arrayCommands[i++]);
	}
	data->get_line = arrayCommands[0];
	for (i = 0; arrayCommands[i]; i++)
	{
		arrayCommands[i] = arrayCommands[i + 1];
		arrayOperators[i] = arrayOperators[i + 1];
	}

	return (stringSize(data->get_line));
}

/**
 * str_tok - This function provides a custom implementation of tokenizing a string based on a delimiter.
 *
 * @line: A pointer to the input string that is being tokenized.
 * @delim: A pointer to a string containing delimiter characters used to split the input string into tokens.
 *
 * Return: The next token in the input string or NULL if there are no more tokens to be found.
 */

char *str_tok(char *line, char *delim)
{
	int num1;
	static char *str;
	char *copyString;

	if (line != NULL)
		str = line;
	for (; *str != '\0'; str++)
	{
		for (num1 = 0; delim[num1] != '\0'; num1++)
		{
			if (*str == delim[num1])
			break;
		}
		if (delim[num1] == '\0')
			break;
	}
	copyString = str;
	if (*copyString == '\0')
		return (NULL);
	for (; *str != '\0'; str++)
	{
		for (num1 = 0; delim[num1] != '\0'; num1++)
		{
			if (*str == delim[num1])
			{
				*str = '\0';
				str++;
				return (copyString);
			}
		}
	}
	return (copyString);
}
