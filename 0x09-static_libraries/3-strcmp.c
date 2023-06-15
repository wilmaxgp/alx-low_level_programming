#include "main.h"

/**
 * _strcmp - function that compares two strings.
 * @s1: String to compare
 * @s2: String to compare
 * Description: function that compares two strings.
 * Return: Always 0.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
		{
			return (0);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}
