#include "main.h"

/**
 * env_builders - handle environment-related commands.
 * @data: it takes a pointer to a structure of type about_info
 * Return: int value
 */

int env_builders(allInfo *data)
{

	char cmd[50] = {'\0'};
	int i;
	char *copyVar = NULL;

	if (data->tokens[1] == NULL)
		envPrint(data);

	else
	{
		for (i = 0; data->tokens[1][i]; i++)
		{
			if (data->tokens[1][i] == '=')
			{
				copyVar = string_repetitions(getKey(cmd, data));
				if (copyVar != NULL)
					setKey(cmd, data->tokens[1] + i + 1, data);
				envPrint(data);
				if (getKey(cmd, data) == NULL)
				{
					terPrint(data->tokens[1]);
					terPrint("\n");
				}
				else
				{
					setKey(cmd, copyVar, data);
					free(copyVar);
				}
				return (0);
			}
			cmd[i] = data->tokens[1][i];
		}
		errno = 2;
		perror(data->cmd_name);
		errno = 127;
	}
	return (0);
}

/**
 * keyUnset - remove an environment variable.
 * @data: it takes a pointer to a structure of type about_info
 * Return: int value
 */

int keyUnset(allInfo *data)
{

	if (data->tokens[1] == NULL)
	{
		return (0);
	}
	if (data->tokens[2] != NULL)
	{
		errno = E2BIG;
		perror(data->cmd_name);
		return (5);
	}

	remove_key(data->tokens[1], data);
	return (0);
}

/**
 * builder_set_key - set or update an environment variable.
 * @data: it takes a pointer to a structure of type about_info
 * Return: int value
 */

int builder_set_key(allInfo *data)
{
	if (data->tokens[1] == NULL || data->tokens[2] == NULL)
		return (0);
	if (data->tokens[3] != NULL)
	{
		errno = E2BIG;
		perror(data->cmd_name);
		return (5);
	}
	setKey(data->tokens[1], data->tokens[2], data);
	return (0);
}
