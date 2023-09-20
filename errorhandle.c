#include "main.h"
/**
 * handle_error - Print error messages based on the given error code
 * and program information
 * @error_code:  an integer representing the error code
 * @info: a pointer to a program_info struct which contains program information
 * Return: zero (0)
*/
int handle_error(int error_code, char *file, char *cmd_name, int *counter)
{
	char *s_counter = intToString(*counter);
	if (error_code == 127)
	{
		print_err(file);
		print_err(": ");
		print_err(s_counter);
		print_err(": ");
		print_err(cmd_name);
		print_err(": not found\n");
	}
	return (0);
}