#include "main.h"

/**
 * *_strdup - it duplicates the string
 * @str: the string to be duplicated
 *
 * Return: pointer to the array or  NULL if not
 */

char *_strdup(char *str)
{
	char *p;
	unsigned int i = 0;
	int len = 0;

	if (str == NULL)
		return (NULL);
	while (str[len])
		len++;
	p = (char *) malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (0);
	while (str[i] != '\0')
	{
		*(p + i) = str[i];
		i++;
	}
	*(p + i) = '\0';
	return (p);
}

/**
 * *str_concat - it concatnates the string
 * @s1: the string to be concatenated
 * @s2: the string to be concatnated
 * Return: pointer to the array or  NULL if not
 */

char *str_concat(char *s1, char *s2)
{
	char *p;
	unsigned int i = 0;
	int len = 0;
	int len2 = 0;
	int j = 0;

	if (s1)
		while (s1[len])
			len++;
	if (s2)
		while (s2[len2])
			len2++;
	p = (char *) malloc(sizeof(char) * (len + len2 + 1));
	if (p == NULL)
		return (0);
	while (s1 != NULL && s1[i] != '\0')
	{
		*(p + i) = s1[i];
		i++;
	}
	while (s2 != NULL && s2[j] != '\0')
	{
		*(p + i + j) = s2[j];
		j++;
	}


	*(p + i + j) = '\0';
	return (p);
}
/**
 * _strlen - count length of string
 * @str: string to be counted
 * Return: unsigned int
 */
unsigned int _strlen(char *str)
{
	unsigned int co = 0;
	while(str[co] != '\0')
		co++;
	return (co);
}