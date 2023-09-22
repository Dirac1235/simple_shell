#include "main.h"

/**
 * logical_operations - This function splits a command array into
 * subcommands based on logical operators.
 *
 * @cmdArr: An array of strings (commands).
 * @num: An integer representing the current position in the cmdArr.
 * @oprArr: An array of characters used to store the logical operators.
 *
 * Return: The number of subcommands created from the input command array.
 */

int logical_operations(char *cmdArr[], int num, char oprArr[])
{
	int firstNum;
	char *temporary = NULL;

	for (firstNum = 0; cmdArr[num] != NULL  && cmdArr[num][firstNum]; firstNum++)
	{
		if (cmdArr[num][firstNum] == '&' && cmdArr[num][firstNum + 1] == '&')
		{
			temporary = cmdArr[num];
			cmdArr[num][firstNum] = '\0';
			cmdArr[num] = string_repetitions(cmdArr[num]);
			cmdArr[num + 1] = string_repetitions(temporary + firstNum + 2);
			num++;
			oprArr[num] = '&';
			free(temporary);
			firstNum = 0;
		}
		if (cmdArr[num][firstNum] == '|' && cmdArr[num][firstNum + 1] == '|')
		{
			temporary = cmdArr[num];
			cmdArr[num][firstNum] = '\0';
			cmdArr[num] = string_repetitions(cmdArr[num]);
			cmdArr[num + 1] = string_repetitions(temporary + firstNum + 2);
			num++;
			oprArr[num] = '|';
			free(temporary);
			firstNum = 0;
		}
	}
	return (num);
}

/**
 * tokenizeData - This function tokenizes an input string,
 * stores tokens in data->tokens,
 * and sets the command name in data->cmd_name.
 *
 * @data: A parameter in these functions that stores information and
 * performs operations related to the program's data and execution.
 *
 * Return: The function doesn't return a value (void).
 */

void tokenizeData(allInfo *data)
{
	char *limiter = " \t";
	int firstNum;
	int secondNum;
	int count = 2;
	int length;

	length = stringSize(data->get_line);
	if (length)
	{
		if (data->get_line[length - 1] == '\n')
			data->get_line[length - 1] = '\0';
	}
	for (firstNum = 0; data->get_line[firstNum]; firstNum++)
	{
		for (secondNum = 0; limiter[secondNum]; secondNum++)
		{
			if (data->get_line[firstNum] == limiter[secondNum])
				count++;
		}
	}
	data->tokens = malloc(count * sizeof(char *));
	if (data->tokens == NULL)
	{
		perror(data->name_projects);
		exit(errno);
	}
	firstNum = 0;
	data->tokens[firstNum] = string_repetitions(str_tok(data->get_line, limiter));
	data->cmd_name = string_repetitions(data->tokens[0]);
	while (data->tokens[firstNum++])
	{
		data->tokens[firstNum] = string_repetitions(str_tok(NULL, limiter));
	}
}
