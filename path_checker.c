#include "main.h"
/**
 * path_checker- finds the pathname of a filename
 * @filename: name of file or command
 * @head: head of linked list of path directories
 * Return: pathname of filename or NULL if no match
 */
char *path_checker(char *filename, char **arr)
{
	struct stat st;
	char *string;
	int i = 0;

	while (arr[i])
	{
	
		string = _strdup(arr[i]);

		string = str_concat(string, "/");
		string = str_concat(string, filename);
		if (stat(string, &st) == 0)
		{
			return (string);
		}
		free(string);
		i++;
	}

	return (NULL);
}