#include "main.h"


/**
 * _strdup -  returns a pointer with copy of the string given as a parameter.
 * Description:  returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter
 * @str: String
 *
 * Return: void
 */
char *_strdup(char *str)
{
	char *duplicate;
	size_t length;

	if (str == NULL)
		return (NULL);

	length = strlen(str) + 1;

	duplicate = (char *)malloc(length * sizeof(char));

	if (duplicate == NULL)
		return (NULL);

	strcpy(duplicate, str);

	return (duplicate);
}
