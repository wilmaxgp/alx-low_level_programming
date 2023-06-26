#include "main.h"

/**
 * is_palindrome - function returns 1 if a string is a palindrome and 0 if not
 * Description: This function checks if a given string is a palindrome.
 * @s: A pointer to a null-terminated string
 *
 * Return: 1 or 0
 */
int is_palindrome_helper(char *s, int start, int end)
{
	if (start >= end)
		return (1);
	
	if (s[start] != s[end])
		return (0);
	
	return is_palindrome_helper(s, start + 1, end - 1);
}

int is_palindrome(char *s)
{
	int len = strlen(s);
	
	return is_palindrome_helper(s, 0, len - 1);
}

