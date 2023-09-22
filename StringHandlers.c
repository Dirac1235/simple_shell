#include "main.h"

/**
 * string_repetitions - This function duplicates a string,
 * (null-terminated character array).
 *
 * @str: A pointer to the null-terminated character array,
 * (string) to be duplicated.
 *
 * Return: A duplicated copy of the input string.
 */

char *string_repetitions(char *str)
{
	int len, first_num;
	char *result;

	if (str == NULL)
		return (NULL);

	len = stringSize(str) + 1;

	result = malloc(sizeof(char) * len);

	if (result == NULL)
	{
		errno = ENOMEM;
		perror("ERROR");
		return (NULL);
	}
	for (first_num = 0; first_num < len ; first_num++)
	{
		result[first_num] = str[first_num];
	}

	return (result);
}


/**
 * _printe - This function prints a character string to the standard error stream.
 *
 * @str: A pointer to the character string to be printed.
 *
 * Return: The number of characters written to the standard error stream.
 */

int errPrint(char *str)
{
	return (write(STDERR_FILENO, str, stringSize(str)));
}


/**
 * string_comparions - This function compares two strings up to a specified number
 *                     of characters.
 *
 * @str_one: The first input string to be compared.
 * @str_two: The second input string to be compared.
 * @num: The number of characters to compare in the strings.
 *
 * Return: 1 if the two input strings are equal up to the specified number of characters,
 *         0 otherwise.
 */

int stringComparitions(char *str_one, char *str_two, int num)
{
	int loop;

	if (str_two == NULL && str_one == NULL)
	{
		return (1);
	}
	if (str_one == NULL || str_two == NULL)
	{
		return (0);
	}
	if (num == 0)
	{
		if (stringSize(str_one) != stringSize(str_two))
			return (0);
		for (loop = 0; str_one[loop]; loop++)
		{
			if (str_one[loop] != str_two[loop])
				return (0);
		}
		return (1);
	}
	else
	{
		for (loop = 0; loop < num ; loop++)
		{
			if (str_one[loop] != str_two[loop])
			return (0);
		}
		return (1);
	}
}