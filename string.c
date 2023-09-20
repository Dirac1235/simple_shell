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
/**
 * _printe - Print a string to the standard error stream
 * @string: a pointer to a character string that needs to be printed
 * Return: the number of characters written to the respective output stream
*/
int print_err(char *string)
{
	return (write(STDERR_FILENO, string, _strlen(string)));
}

char  *intToString(int number) 
{
    
    int isNegative = 0;
    int temp;
    int numDigits = 1;
    char* str;
    int divisor = 1;
    char* ptr;
	int digit;
	int i;
	
    if (number < 0) {
        isNegative = 1;
        number = -number;
    }

    

	temp = number;
    while (temp >= 10) {
        temp /= 10;
        numDigits++;
    }


	str = (char*)malloc(numDigits + isNegative + 1);
    if (str == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
	ptr = str;

    if (isNegative) {
        *ptr = '-';
        ptr++;
    }


    for (i = 1; i < numDigits; i++) {
        divisor *= 10;
    }

    while (divisor >= 1) {
        digit = number / divisor;
        *ptr = '0' + digit;
        ptr++;
        number -= digit * divisor;
        divisor /= 10;
    }

    *ptr = '\0'; 

    return str;
}