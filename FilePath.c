#include "main.h"

/**
 * search_file - This function looks for the presence of an executable file
 *               in the directories listed in the PATH environment variable
 *               and updates the command path accordingly.
 *
 * @data: A pointer to a structure of type "about" containing various
 *        details about the program's execution and environment.
 *
 * Return: An exit code based on whether the executable file was found
 *         in the directories listed in the PATH environment variable.
 */

int searchFile(allInfo *data)
{
	int firstNum = 0, returnCode = 0;
	char **dir;

	if (!data->cmd_name)
		return (2);
	if (data->cmd_name[0] == '/' || data->cmd_name[0] == '.')
		return (check(data->cmd_name));
	free(data->tokens[0]);
	data->tokens[0] = mergeString(string_repetitions("/"), data->cmd_name);
	if (!data->tokens[0])
		return (2);
	dir = filePath(data);
	if (!dir || !dir[0])
	{
		errno = 127;
		return (127);
	}
	for (firstNum = 0; dir[firstNum]; firstNum++)
	{
		dir[firstNum] = mergeString(dir[firstNum], data->tokens[0]);
		returnCode = check(dir[firstNum]);
		if (returnCode == 0 || returnCode == 126)
		{
			errno = 0;
			free(data->tokens[0]);
			data->tokens[0] = string_repetitions(dir[firstNum]);
			free_array_pointes(dir);
			return (returnCode);
		}
	}
	free(data->tokens[0]);
	data->tokens[0] = NULL;
	free_array_pointes(dir);
	return (returnCode);
}

/**
 * path_of_file - This function retrieves directories from the PATH environment variable,
 *                tokenizes them, and returns them as an array of strings.
 *
 * @data: A pointer to a "program_data" structure within the functions.
 *
 * Return: An array of strings containing directories extracted from the PATH environment variable.
 */

char **filePath(allInfo *data)
{
	int i = 0;
	int countDirectories = 2;
	char **tokens = NULL;
	char *PATH;

	PATH = getKey("PATH", data);
	if ((PATH == NULL) || PATH[0] == '\0')
	{
		return (NULL);
	}
	PATH = string_repetitions(PATH);
	for (i = 0; PATH[i]; i++)
	{
		if (PATH[i] == ':')
			countDirectories++;
	}
	tokens = malloc(sizeof(char *) * countDirectories);
	i = 0;
	tokens[i] = string_repetitions(str_tok(PATH, ":"));
	while (tokens[i++])
	{
		tokens[i] = string_repetitions(str_tok(NULL, ":"));
	}
	free(PATH);
	PATH = NULL;
	return (tokens);
}

/**
 * check - a functions checks if a file exists and is executable
 * @file_path: a string representing the path to the file being
 * checked for existence
 * Return: 0 if the file at the specified path exists and is executable
 * 126 if it exists but is not executable, and 127 if the file does not exist
*/
int check(char *file_path)
{
	struct stat sb;

	if (stat(file_path, &sb) != -1)
	{
		if (S_ISDIR(sb.st_mode) ||  access(file_path, X_OK))
		{
			errno = 126;
			return (126);
		}
		return (0);
	}
	errno = 127;
	return (127);
}
