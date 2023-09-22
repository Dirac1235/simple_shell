#include "main.h"

/**
 *  exit_env - handle the "exit" command in the shell.
 * The "exit" command is used to terminate the shell program.
 * @data: structure of type about_info
 * Return: int value
*/

int exit_env(allInfo *data)
{
	int i;

	if (data->tokens[1] != NULL)
	{
		for (i = 0; data->tokens[1][i]; i++)
			if ((data->tokens[1][i] < '0' || data->tokens[1][i] > '9')
				&& data->tokens[1][i] != '+')
			{
				errno = 2;
				return (2);
			}
		errno = _atoi(data->tokens[1]);
	}
	if (data != NULL)
	{
		freeAll(data);
	}
	exit(errno);
}

/**
 * set_dir - switch the current working directory to a new
 * @data: This structure presumably contains information related
 * to the program.
 * @newDir:  It takes a string pointer newDir
 * Return: int value
 */

int set_dir(allInfo *data, char *newDir)
{
	char oldDir[128] = {0};
	int errorData = 0;

	getcwd(oldDir, 128);

	if (!stringComparitions(oldDir, newDir, 0))
	{
		errorData = chdir(newDir);
		if (errorData == -1)
		{
			errno = 2;
			return (3);
		}
		setKey("PWD", newDir, data);
	}
	setKey("OLDPW", oldDir, data);
	return (0);
}

/**
 * builtin_alias - execute the alias command in a shell program.
 * @data:  It takes a pointer to a structure of type about_info
 * Return: int value
 */

int builtin_alias(allInfo *data)
{
	int i = 0;

	if (data->tokens[1] == NULL)
		return (printfFun(data, NULL));

	while (data->tokens[++i])
	{
		if (size_characters(data->tokens[i], "="))
			set_fun(data->tokens[i], data);
		else
			printfFun(data, data->tokens[i]);
	}
	return (0);
}
