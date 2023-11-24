#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: Pointer to a string of 0 and 1 chars (binary number)
 *
 * Return: The converted number (n), or 0 if:
 *  - There is one or more chars in the string b that is not 0 or 1
 *  - b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int n = 0;

	if (b == NULL)
		return (0);

	while (*b)
	{
		if (*b != '0' && *b != '1')
			return (0);

		n = (n * 2) + (*b - '0');
		b++;
	}

	return (n);
}
