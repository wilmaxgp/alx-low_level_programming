#include "main.h"

/**
 * square_root - Calculates the square root recursively
 * @n: The number to calculate the square root of
 * @guess: The current guess for the square root
 *
 * Return: The natural square root of n,
 * or -1 if n doesn't have a natural square root
 */
int square_root(int n, int guess)
{
	if (guess * guess == n)
		return (guess);
	else if (guess * guess > n)
		return (-1);
	else
		return (square_root(n, guess + 1));
}

/**
 * _sqrt_recursion - Returns the natural square root of a number
 * @n: The number to calculate the square root of
 *
 * Return: The natural square root of n,
 * or -1 if n doesn't have a natural square root
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	else
		return (square_root(n, 0));
}

