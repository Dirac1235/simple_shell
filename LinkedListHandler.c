#include "main.h"

/**
 * This function, 'free_data,' is responsible for releasing allocated memory
 * and ensuring that the pointers within the 'program_info' structure are set to NULL.
 * @data: A pointer to a 'program_info' structure, which typically holds
 * information related to a program, such as environment variables.
 * Return: This function doesn't return any value; it's a void function.
*/
void freeData(allInfo *data)
{
	if (data->tokens)
		free_array_pointes(data->tokens);
	if (data->get_line)
		free(data->get_line);
	if (data->cmd_name)
		free(data->cmd_name);
	data->get_line = NULL;
	data->cmd_name = NULL;
	data->tokens = NULL;
}

/**
 * free_array_pointers - This function deallocates the memory allocated for an array,
 * of pointers and sets the array itself to NULL.
 *
 * @list: A pointer to an array of pointers.
 *
 * Return: It doesn't return any value (void function).
 */

void free_array_pointes(char **list)
{
	int num1;

	if (list != NULL)
	{
		for (num1 = 0; list[num1]; num1++)
			free(list[num1]);
		free(list);
		list = NULL;
	}
}

/**
 * free_all - Free allocated memory and close a file descriptor,
 * if applicable, in the `about` struct.
 * @data: a pointer to a program_info structure, likely containing
 * program-related information and environment variables.
 * Return: It doesn't return any value (void function)
*/
void freeAll(allInfo *data)
{
	if (data->file_desc != 0)
	{
		if (close(data->file_desc))
			perror(data->name_projects);
	}
	freeData(data);
	free_array_pointes(data->env);
	free_array_pointes(data->alias_list);
}

