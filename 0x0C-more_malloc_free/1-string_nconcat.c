#include "main.h"


/**
 * string_nconcat - function that concatenates two strings
 * Description: a function that concatenates two strings.
 * @s1: pointer to the first string to be concatenated
 * @s2: pointer to the second string to be concatenated
 * @n: unsigned integer of the number of characters from s2 to concatenate
 *
 * Return: pointer to a newly allocated space in memory or NULL if it fails.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
       	unsigned int len1, len2, concat_len;
       	char *concat;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	len1 = strlen(s1);
	len2 = strlen(s2);

	if (n >= len2)
		n = len2;

	concat_len = len1 + n;

	concat = malloc((concat_len + 1) * sizeof(char));
	if (concat == NULL)
		return NULL;

	strcpy(concat, s1);

	strncat(concat, s2, n);

	return concat;
}
