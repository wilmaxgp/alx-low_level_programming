#include "main.h"

/**
 * _isalpha - function that prints the lowercase alphabet.
 * @c: ASCII equivalent integer.
 * Description: function that prints the lowercase alphabet.
 * Return: 1 if Alphabet character Lower or Upper  and 0 otherwise.
 */
int _isalpha(int c)
{
	return ((c >= 97 && c <= 122) || (c >= 65 && c <= 90));
}
