#include "main.h"

/**
 * expandVar - This function processes and expands variables in a given text line
 * stored in the "info" structure.
 *
 * @data: A struct of type "about_info" in the function "expandVar."
 *
 * Return: This function does not have a return value (void).
 */

void expandVar(allInfo *data)
{
	int num1, num2;
	char line[BUFFER_SIZE] = {0}, expansion[BUFFER_SIZE] = {'\0'}, *temp;

	if (data->get_line == NULL)
		return;
	new_buffer(line, data->get_line);
	for (num1 = 0; line[num1]; num1++)
		if (line[num1] == '#')
			line[num1--] = '\0';
		else if (line[num1] == '$' && line[num1 + 1] == '?')
		{
			line[num1] = '\0';
			stringLong(errno, expansion, 10);
			new_buffer(line, expansion);
			new_buffer(line, data->get_line + num1 + 2);
		} else if (line[num1] == '$' && line[num1 + 1] == '$')
		{
			line[num1] = '\0';
			stringLong(getpid(), expansion, 10);
			new_buffer(line, expansion);
			new_buffer(line, data->get_line + num1 + 2);
		} else if (line[num1] == '$' && (line[num1 + 1] == ' '
		|| line[num1 + 1] == '\0'))
			continue;
		else if (line[num1] == '$')
		{
			for (num2 = 1; line[num1 + num2] && line[num1 + num2] != ' '; num2++)
				expansion[num2 - 1] = line[num1 + num2];
			temp = getKey(expansion, data);
			line[num1] = '\0', expansion[0] = '\0';
			new_buffer(expansion, line + num1 + num2);
			temp ? new_buffer(line, temp) : 1;
			new_buffer(line, expansion);
		}
	if (!stringComparitions(data->get_line, line, 0))
	{
		free(data->get_line);
		data->get_line = string_repetitions(line);
	}
}

/**
 * expand_alias - This function searches for and expands aliases in the provided
 * input line stored in "info->get_line."
 *
 * @data: A struct of type "about_info" in the function "expandVar."
 *
 * Return: This function does not have a return value (void).
 */

void expand_alias(allInfo *data)
{
	int i;
	int j;
	int isExpanded = 0;
	char line[BUFFER_SIZE] = {0};
	char expansion[BUFFER_SIZE] = {'\0'};
	char *temp;

	if (data->get_line == NULL)
		return;
	new_buffer(line, data->get_line);
	for (i = 0; line[i]; i++)
	{
		for (j = 0; line[i + j] && line[i + j] != ' '; j++)
			expansion[j] = line[i + j];
		expansion[j] = '\0';

		temp = getFun(data, expansion);
		if (temp)
		{
			expansion[0] = '\0';
			new_buffer(expansion, line + i + j);
			line[i] = '\0';
			new_buffer(line, temp);
			line[stringSize(line)] = '\0';
			new_buffer(line, expansion);
			isExpanded = 1;
		}
		break;
	}
	if (isExpanded)
	{
		free(data->get_line);
		data->get_line = string_repetitions(line);
	}
}

/**
 * new_buffer - This function appends the "concatenate_string" to the end of the "buffer."
 *
 * @buf: A character array to which "concatenate_string" is appended.
 * @concatStr: A string that is concatenated to "buffer."
 *
 * Return: The total length of the resulting string after appending "concatenate_string" to "buffer."
 */

int new_buffer(char *buf, char *concatStr)
{
	int firstNum, secondNum;

	firstNum = stringSize(buf);
	for (secondNum = 0; concatStr[secondNum]; secondNum++)
	{
		buf[firstNum + secondNum] = concatStr[secondNum];
	}
	buf[firstNum + secondNum] = '\0';
	return (firstNum + secondNum);
}
