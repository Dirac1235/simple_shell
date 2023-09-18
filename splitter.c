#include "main.h"
/**
 * split_path - creates a linked list for path directories
 * @path: string of path value
 * Return: pointer to the created linked list
 */
char **split_path(char *path)
{
	
	char *token;
	char *cpath = _strdup(path);
	char **array;
	int i = 0;
	
	array = malloc(sizeof(char *) * (_strlen(path))/2);

	token = strtok(cpath, ":");
	while (token)
	{
		*array = malloc(sizeof(char) * _strlen(token));
		array[i] = token;
		token = strtok(NULL, ":");
		i++;
	}
	array[i] = NULL;

	return (array);
}