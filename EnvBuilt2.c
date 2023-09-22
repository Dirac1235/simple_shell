#include "main.h"

/**
 * built_list - handle built-in commands in the shell
 * @data: It takes a pointer to a structure of type about_info
 * Return: int value
 */

int builtList(allInfo *data)
{
	int nums;
	env_structure listMenu[] = {
		{"exit", exit_env},
		{"unsetenv", keyUnset},
		{"cd", commandBuilt},
		{"alias", builtin_alias},
		{"env", env_builders},
		{"help", helpBuilt},
		{"setenv", builder_set_key},
		{NULL, NULL}
	};

	for (nums = 0; listMenu[nums].built_in != NULL; nums++)
	{
		if (stringComparitions(listMenu[nums].built_in, data->cmd_name, 0))
		{
			return (listMenu[nums].function(data));
		}
	}
	return (-1);
}

/**
 * command_built - handle the "cd" command,
 * which is used to change the current working directory.
 * @data: It takes a pointer to a structure of type about_info
 * Return: int value
 */

int commandBuilt(allInfo *data)
{
	int Error = 0;
	char *homeDir = getKey("HOME", data), *oldDir = NULL;
	char old_Dir[128] = {0};

	if (data->tokens[1])
	{
		if (stringComparitions(data->tokens[1], "-", 0))
		{
			oldDir = getKey("OLDPWD", data);
			if (oldDir)
				Error = set_dir(data, oldDir);
			terPrint(getKey("PWD", data));
			terPrint("\n");
			return (Error);
		}
		else
		{
			return (set_dir(data, data->tokens[1]));
		}
	}
	else
	{
		if (!homeDir)
			homeDir = getcwd(old_Dir, 128);

		return (set_dir(data, homeDir));
	}
	return (0);
}

/**
 * help_built - provide help messages for built-in commands in the shell.
 * It checks the entered command against a list of known commands and displays
 * the corresponding help message.
 * @data: It takes a pointer to a structure of type about_info
 * Return: int value
 */

int helpBuilt(allInfo *data)
{
	int i;
	int len = 0;
	char *messages_info[6] = {NULL};

	messages_info[0] = HELP_MSG;
	if (data->tokens[1] == NULL)
	{
		terPrint(messages_info[0] + 6);
		return (1);
	}
	if (data->tokens[2] != NULL)
	{
		errno = E2BIG;
		perror(data->cmd_name);
		return (5);
	}
	messages_info[1] = HELP_EXIT_MSG;
	messages_info[2] = HELP_ENV_MSG;
	messages_info[3] = HELP_SETENV_MSG;
	messages_info[4] = HELP_UNSETENV_MSG;
	messages_info[5] = HELP_CD_MSG;
	for (i = 0; messages_info[i]; i++)
	{
		len = stringSize(data->tokens[1]);
		if (stringComparitions(data->tokens[1], messages_info[i], len))
		{
			terPrint(messages_info[i] + len + 1);
			return (1);
		}
	}
	errno = EINVAL;
	perror(data->cmd_name);
	return (0);
}
