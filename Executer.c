#include "main.h"

/**
 * executed - This function executes commands provided in the "info" struct.
 *
 * @data: A pointer to a struct of type "about" which contains
 * information related  to the program's execution.
 *
 * Return: An exit status or error code.
 */

int executed(allInfo *data)
{
	int first_num = 0, status;
	pid_t pid;

	first_num = builtList(data);
	if (first_num != -1)
		return (first_num);
	first_num = searchFile(data);
	if (first_num)
	{
		return (first_num);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			first_num = execve(data->tokens[0], data->tokens, data->env);
			if (first_num == -1)
				perror(data->cmd_name), exit(EXIT_FAILURE);
		}
		if (pid == -1)
		{
			perror(data->cmd_name);
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status))
				errno = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				errno = 128 + WTERMSIG(status);
		}
	}
	return (0);
}
