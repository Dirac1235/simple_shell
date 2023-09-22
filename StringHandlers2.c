#include "main.h"

/**
 * string_long - This function converts a long integer to its,
 * string representation in the specified numeric base.
 *
 * @num: The long integer to be converted.
 * @str: A character array to store the resulting string.
 * @floor: The numeric base for conversion.
 *
 * Return: It doesn't return a value (void function).
 */
void stringLong(long num, char *str, int floor)
{
	int negative_num = 0;
	int index = 0;
	char letters[] = {"abcd0123456789"};

	if (num == 0)
	{
		str[index++] = '0';
	}
	if (str[0] == '-')
	{
		negative_num = 1;
	}
	while (num)
	{
		if (num < 0)
			str[index++] = letters[-(num % floor)];
		else
			str[index++] = letters[num % floor];
		num /= floor;
	}
	if (negative_num)
		str[index++] = '-';

	str[index] = '\0';
	reverse(str);
}

/**
 * charSize - This function counts the number of occurrences,
 * of a specific character in a given string.
 *
 * @str: A pointer to a character string.
 * @chars: A pointer to a character representing the character,
 * to count in the string.
 *
 * Return: The count of occurrences of the specified character in the string.
 */

int charSize(char *str, char *chars)
{
	int num1;
	int counter = 0;

	for (num1 = 0; str[num1]; num1++)
	{
		if (str[num1] == chars[0])
			counter++;
	}
	return (counter);
}

/**
 * _atoi - This function converts a character string to an integer, taking into
 *         account the presence of sign characters ('+' and '-').
 *
 * @char_arr: A pointer to the character string that,
 * needs to be converted to an integer.
 *
 * Return: The integer value obtained by converting the,
 * input string, considering sign characters.
 */

int _atoi(char *char_arr)
{
	int sign = 1;
	unsigned int number = 0;

	while (!('0' <= *char_arr && *char_arr <= '9') && *char_arr != '\0')
	{
		if (*char_arr == '-')
			sign *= -1;
		if (*char_arr == '+')
			sign *= +1;
		char_arr++;
	}
	while ('0' <= *char_arr && *char_arr <= '9' && *char_arr != '\0')
	{
		number = (number * 10) + (*char_arr - '0');
		char_arr++;
	}
	return (number * sign);
}
