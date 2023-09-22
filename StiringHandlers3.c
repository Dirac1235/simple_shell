#include "main.h"

/**
 * stringSize - This function calculates the length of the input string.
 *
 * @str: A pointer to a character array (a string) whose,
 * length needs to be determined.
 *
 * Return: The length of the input string excluding the,
 * null terminator, or 0 if the string is NULL.
 */

int stringSize(char *str)
{
	int counter = 0;

	if (str == NULL)
		return (0);
	while (str[counter++] != '\0')
	{
	}
	return (counter - 1);
}

/**
 * mergeString - This function concatenates,
 * two strings (str_one and str_two).
 *
 * @str_one: Character array representing the first string.
 * @str_two: Character array representing the second string.
 *
 * Return: The merged string obtained by concatenating str_one and str_two.
 */

char *mergeString(char *str_one, char *str_two)
{
	char *result;
	int num1 = 0, num2 = 0;

	if (str_one == NULL)
		str_one = "";
	num1 = stringSize(str_one);
	if (str_two == NULL)
		str_two = "";
	num2 = stringSize(str_two);
	result = malloc(sizeof(char) * (num1 + num2 + 1));
	if (result == NULL)
	{
		errno = ENOMEM;
		perror("ERROR");
		return (NULL);
	}

	for (num1 = 0; str_one[num1] != '\0'; num1++)
		result[num1] = str_one[num1];
	free(str_one);
	for (num2 = 0; str_two[num2] != '\0'; num2++)
	{
		result[num1] = str_two[num2];
		num1++;
	}
	result[num1] = '\0';
	return (result);
}

/**
 * reverse - This function reverses the characters in a given string.
 *
 * @str: A character array (string) to be reversed.
 *
 * Return: This function does not return a value.
 */

void reverse(char *str)
{

	int num1 = 0, length = stringSize(str) - 1;
	char hold;

	while (num1 < length)
	{
		hold = str[num1];
		str[num1++] = str[length];
		str[length--] = hold;
	}
}

/**
 * _print - This function prints a character,
 * string to the standard output stream.
 *
 * @str: A pointer to the character string to be printed.
 *
 * Return: The number of characters written to the standard output stream.
 */

int terPrint(char *str)
{
	return (write(STDOUT_FILENO, str, stringSize(str)));
}
