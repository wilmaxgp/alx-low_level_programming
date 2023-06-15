#include "main.h"

/**
 * _strstr- function that locates a substring.
 * @haystack: string to search
 * @needle: characters string to look out for
 * Description: function that locates a substring.
 * Return: Always 0
 */
char *_strstr(char *haystack, char *needle)
{
	unsigned int n_index, h_index;

	for (h_index = 0; haystack[h_index] != '\0' ; h_index++)
	{
		for (n_index = 0; needle[n_index] != '\0'; n_index++)
		{
			if (haystack[h_index + n_index] != needle[n_index])
			{
				break;
			}
		}
		if (!needle[n_index])
			return (haystack + h_index);
	}

	return (0);
}
