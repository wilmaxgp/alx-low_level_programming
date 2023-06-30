#include "main.h"

/**
 * str_concat - function that concatenates two strings.
 * Description: function that concatenates two strings.
 * @s1: A pointer to the first input string.
 * @s2: A pointer to the second input string
 *
 * Return: void
 */
char *str_concat(char *s1, char *s2)
{
	char *result;
	size_t s1_len;
	size_t s2_len;


	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";


	s1_len = strlen(s1);
	s2_len = strlen(s2);

	result = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));

	if (result == NULL)
		return NULL;


	strcpy(result, s1);
	strcpy(result + s1_len, s2);


	return result;
}
