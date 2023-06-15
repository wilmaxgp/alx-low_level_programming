#include "main.h"

/**
 * _strpbrk - function that searches a string for any of a set of bytes.
 * @s: string to search
 * @accept: characters to look out for
 * Description: function that searches a string for any of a set of bytes.
 * Return: 1 if Alphabet character Lower or Upper  and 0 otherwise.
 */
char *_strpbrk(char *s, char *accept)
{
	while (*s != '\0')
	{
		char *a = accept;

		while (*a != '\0')
		{
			if (*a == *s)
			{
				return (s);
			}
			a++;
		}
		s++;
	}
	return ('\0');
}
