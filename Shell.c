#include "main.h"

/**
 * main - The main function initializes program structures, sets up signal handling,
 *        and decides whether to display a prompt message based on input and terminal
 *        conditions.
 *
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to the command-line arguments.
 * @env: An array of pointers to environment variables.
 *
 * Return: Always 0
 */

int main(int argc, char *argv[], char *env[])
{
	allInfo stru_data = {NULL}, *info = &stru_data;
	char *prompt = "";

	start_with(info, argc, argv, env);
	signal(SIGINT, handleShortCut);
	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && argc == 1)
	{
		errno = 2;
		prompt = PROMPT_MSG;
	}
	errno = 0;
	size_of_(prompt, info);
	return (0);
}

/**
 * handle_short_cut - Prints a newline and the PROMPT_MSG as a command prompt.
 * @UNUSED: Intentionally unused parameter to suppress compiler warnings.
 * Return: No return value.
 */

void handleShortCut(int operations UNUSED)
{
	terPrint("\n");
	terPrint(PROMPT_MSG);
}

/**
 * start_with - Initializes 'about' struct using 'argc', 'argv', and 'env' for the shell program.
 *
 * @info: Pointer to 'about' struct.
 * @argc: Command-line argument count.
 * @argv: Command-line argument array.
 * @env: Environment variable array.
 *
 * Return: No return value.
 */

void start_with(allInfo *info, int argc, char *argv[], char **env)
{
	int firstNum = 0;

	info->name_projects = argv[0];
	info->get_line = NULL;
	info->cmd_name = NULL;
	info->execute_counter = 0;
	if (argc == 1)
		info->file_desc = STDIN_FILENO;
	else
	{
		info->file_desc = open(argv[1], O_RDONLY);
		if (info->file_desc == -1)
		{
			errPrint(info->name_projects);
			errPrint(": 0: does not open ");
			errPrint(argv[1]);
			errPrint("\n");
			exit(127);
		}
	}
	info->tokens = NULL;
	info->env = malloc(sizeof(char *) * 50);
	if (env)
	{
		for (; env[firstNum]; firstNum++)
		{
			info->env[firstNum] = string_repetitions(env[firstNum]);
		}
	}
	info->env[firstNum] = NULL;
	env = info->env;
	info->alias_list = malloc(sizeof(char *) * 20);
	for (firstNum = 0; firstNum < 20; firstNum++)
	{
		info->alias_list[firstNum] = NULL;
	}
}

/**
 * size_of_ - Reads and processes input lines, executing commands
 *            in a shell-like environment with the given prompt.
 *
 * @prompt: The prompt message as a string.
 * @info: A pointer to a struct containing program information.
 *
 * Return: No return value.
 */

void size_of_(char *prompt, allInfo *info)
{
	int errorCode = 0, stringLen = 0;

	while (++(info->execute_counter))
	{
		terPrint(prompt);
		errorCode = stringLen = _getline(info);
		if (errorCode == EOF)
		{
			freeAll(info);
			exit(errno);
		}
		if (stringLen >= 1)
		{
			expand_alias(info);
			expandVar(info);
			tokenizeData(info);
			if (info->tokens[0])
			{
				errorCode = executed(info);
				if (errorCode != 0)
					handle_error(errorCode, info);
			}
			freeData(info);
		}
	}
}
