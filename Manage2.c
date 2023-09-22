#include "main.h"

/**
 * get_key - retrieve the value associated with
 * a specified environment variable (key) from the
 * data->env array.
 * @key: a character array, representing a key (environment variable).
 * @data: it takes a pointer to a structure of type about_info
 * Return: char*
 */

char *getKey(char *key, allInfo *data)
{
	int i, keyLen = 0;

	if (key == NULL || data->env == NULL)
		return (NULL);
	keyLen = stringSize(key);
	for (i = 0; data->env[i]; i++)
	{
		if (stringComparitions(key, data->env[i], keyLen) &&
			data->env[i][keyLen] == '=')
		{
			return (data->env[i] + keyLen + 1);
		}
	}
	return (NULL);
}

/**
 * set_key - set or update an environment variable (key)
 * with a specified value (value) in the data->env array.
 * @key: a character array, representing a key (environment variable).
 * @value: representing a value for the environment variable.
 * @data: it takes a pointer to a structure of type about_info
 * Return: int value
 */

int setKey(char *key, char *value, allInfo *data)
{
	int i, keyLen = 0;
	int newKey = 1;

	if (key == NULL || value == NULL || data->env == NULL)
		return (1);

	keyLen = stringSize(key);
	for (i = 0; data->env[i]; i++)
	{
		if (stringComparitions(key, data->env[i], keyLen) &&
			data->env[i][keyLen] == '=')
		{
			newKey = 0;
			free(data->env[i]);
			break;
		}
	}

	data->env[i] = mergeString(string_repetitions(key), "=");
	data->env[i] = mergeString(data->env[i], value);
	if (newKey)
		data->env[i + 1] = NULL;

	return (0);
}

/**
 * env_print - print the environment variables stored in the data->env array.
 * @data: it takes a pointer to a structure of type about_info
 */

void envPrint(allInfo *data)
{
	int i;

	for (i = 0; data->env[i]; i++)
	{
		terPrint(data->env[i]);
		terPrint("\n");
	}
}

/**
 * remove_key - remove an environment variable (key) from the data->env array.
 * @key: a character array, representing a key (environment variable).
 * @data: it takes a pointer to a structure of type about_info
 * Return: int value
 */

int remove_key(char *key, allInfo *data)
{
	int i;
	int keyLen = 0;

	if (key == NULL || data->env == NULL)
		return (0);
	keyLen = stringSize(key);
	for (i = 0; data->env[i]; i++)
	{
		if (stringComparitions(key, data->env[i], keyLen) &&
			data->env[i][keyLen] == '=')
		{
			free(data->env[i]);
			i++;
			for (; data->env[i]; i++)
			{
				data->env[i - 1] = data->env[i];
			}
			data->env[i - 1] = NULL;
			return (1);
		}
	}

	return (0);
}
