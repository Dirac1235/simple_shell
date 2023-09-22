#include "main.h"

/**
 * handle_error - This function prints error messages based
 * on the provided error code and program information.
 *
 * @e_code: An integer representing the error code.
 * @data: A pointer to a program_info struct
 * which contains program information.
 *
 * Return: Zero (0).
 */

int handle_error(int e_code, allInfo *data)
{
	char arr_string[10] = {'\0'};

	stringLong((long) data->execute_counter, arr_string, 10);
	if (e_code == 2 || e_code == 3)
	{
		errPrint(data->name_projects);
		errPrint(": ");
		errPrint(arr_string);
		errPrint(": ");
		errPrint(data->tokens[0]);
		if (e_code == 2)
			errPrint(": ERROR (unexpected number): ");
		else
			errPrint(": ERROR (can not redirect): ");
		errPrint(data->tokens[1]);
		errPrint("\n");
	}
	else if (e_code == 127)
	{
		errPrint(data->name_projects);
		errPrint(": ");
		errPrint(arr_string);
		errPrint(": ");
		errPrint(data->cmd_name);
		errPrint(": ERROR (not found)\n");
	}
	else if (e_code == 126)
	{
		errPrint(data->name_projects);
		errPrint(": ");
		errPrint(arr_string);
		errPrint(": ");
		errPrint(data->cmd_name);
		errPrint(": ERROR (no permission)\n");
	}
	return (0);
}


