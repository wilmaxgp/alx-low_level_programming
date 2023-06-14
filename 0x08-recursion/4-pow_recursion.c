#include "main.h"
#include <math.h>

/**
 * _pow_recursion:-function that returns the value x raised to the power of y.
 * @x: integer of x
 * @y: integer of y
 * Description: function returns the value of x raised to the power of y.
 * Return: Always int.
 **/

int _pow_recursion(int x, int y)
{
	if (y < 0)
	{
		return (-1);
	}
	else if (y == 0)
	{
		return (1);
	}
	else
	{
		return (x * _pow_recursion(x, y - 1));
	}
}
