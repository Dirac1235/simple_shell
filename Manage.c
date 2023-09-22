#include "main.h"

/**
 * getFun - retrieve the value associated
 * with a given Name from a list of aliases.
 * @data: It takes a pointer to a structure of type about_info
 * @Name: character array, representing a Name
 * Return: a character pointer.
 */

char *getFun(allInfo *data, char *Name)
{
	int i;
	int len;

	if (Name == NULL || data->alias_list == NULL)
		return (NULL);

	len = stringSize(Name);
	for (i = 0; data->alias_list[i]; i++)
	{
		if (stringComparitions(Name, data->alias_list[i], len) &&
			data->alias_list[i][len] == '=')
			return (data->alias_list[i] + len + 1);
	}

	return (NULL);
}

/**
 * printFun - print information about aliases stored in data->alias_list
 * @data: it takes a pointer to a structure of type about_info
 * @Name: character array, representing a Name
 * Return: int value
 */

int printfFun(allInfo *data, char *Name)
{
	char buffer[250] = {'\0'};
	int len;
	int i;
	int j;

	if (data->alias_list)
	{
		len = stringSize(Name);
		for (i = 0; data->alias_list[i]; i++)
		{
			if (!Name || (stringComparitions(data->alias_list[i], Name, len)
				&&	data->alias_list[i][len] == '='))
			{
				for (j = 0; data->alias_list[i][j]; j++)
				{
					buffer[j] = data->alias_list[i][j];
					if (data->alias_list[i][j] == '=')
					{
						break;
					}
				}
				buffer[j + 1] = '\0';
				new_buffer(buffer, "'");
				new_buffer(buffer, data->alias_list[i] + j + 1);
				new_buffer(buffer, "'\n");
				terPrint(buffer);
			}
		}
	}

	return (0);
}

/**
 * set_fun - add or update an alias in the data->alias_list
 * @alias_string: pointer to a character array, representing an alias string.
 * @data: it takes a pointer to a structure of type about_info
 * Return: int value
 */

int set_fun(char *alias_string, allInfo *data)
{
	char buffer[250] = {'0'}, *temp = NULL;
	int j;
	int i;

	if (alias_string == NULL ||  data->alias_list == NULL)
		return (1);
	for (i = 0; alias_string[i]; i++)
		if (alias_string[i] != '=')
			buffer[i] = alias_string[i];
		else
		{
			temp = getFun(data, alias_string + i + 1);
			break;
		}
	for (j = 0; data->alias_list[j]; j++)
		if (stringComparitions(buffer, data->alias_list[j], i) &&
			data->alias_list[j][i] == '=')
		{
			free(data->alias_list[j]);
			break;
		}

	if (temp)
	{
		new_buffer(buffer, "=");
		new_buffer(buffer, temp);
		data->alias_list[j] = string_repetitions(buffer);
	}
	else
		data->alias_list[j] = string_repetitions(alias_string);
	return (0);
}
