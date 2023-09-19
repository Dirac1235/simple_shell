#include "main.h"

/**
 * ext - exits the shell
 * @arr: array of words of the entered line
 */
void ext(char **arr)
{
	int i;
	free(arr);
	exit(0);
}