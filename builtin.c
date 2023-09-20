#include "main.h"

/**
 * ext - exits the shell
 * @arr: array of words of the entered line
 */
void ext(char **arr)
{
	free(arr);
	exit(0);
}