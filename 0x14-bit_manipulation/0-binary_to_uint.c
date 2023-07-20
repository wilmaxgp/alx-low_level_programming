#include "main.h"

/**
 * binary_to_uint - function that converts a binary number to an unsigned int
 * @b: Pointer to a string of 0 and 1 chars
 *
 * Description: function that converts a binary number to an unsigned int.
 * Return: converted number, or 0
 */
unsigned int binary_to_uint(const char *b)
{
	int i
	unsigned int result;

	if (b == NULL)
		return (0);

	result = 0;


	i = 0;

	while (b[i] != '\0')
	{
		if (b[i] == '0' || b[i] == '1')
		{
			result = result * 2 + (b[i] - '0');
			i++;
		}
		else
		{
			return (0);        
		}
	}

	return (result);
}
