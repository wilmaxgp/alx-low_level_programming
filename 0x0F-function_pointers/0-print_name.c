#include "function_pointers.h"
#include "stdio.h"
#include "stddef.h"

/**
 * print_name - function that prints a name
 * @name: name of the person
 *
 * Return: Nothing.
 */
void print_name(char *name, void (*f)(char *))
{
	f(name);
}
