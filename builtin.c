#include "main.h"

/**
 * ext - exits the shell
 * @arv: array of words of the entered line
 */
void ext(char **arv)
{
	int i;
	free(arv);
	exit(0);
}