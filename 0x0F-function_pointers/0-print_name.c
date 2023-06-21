#include "function_pointers.h"
#include "stdio.h"
#include "stddef.h"

/**
 * print_name - function that prints a name
 * @name: name of the person
 * @f: function pointer
 *
 * Return: Nothing.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != 0 && f != 0)
		f(name);
}
