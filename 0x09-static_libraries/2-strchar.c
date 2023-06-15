#include "main.h"

/**
 * _strchr - function locates a character in a string.
 * @s: string to search
 * @c: character to search for
 * Description: function locates a character in a string.
 * Return: Always 0.
 */
char *_strchr(char *s, char c)
{
	int index, s_length;

	s_length = 0;

	for (index = 0; *(s + index) != '\0'; index++)
		s_length++;

	index = 0;

	while (index <= s_length)
	{
		if (*(s + index) == c)
			return (s + index);
		index++;
	}

	return (0);
}
