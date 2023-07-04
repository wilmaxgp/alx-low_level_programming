#include "lists.h"

/**
 * first_message - function that prints first_message befor printing main
 * 
 * Description: function that prints first_message befor printing main
 * Return: void
 */
void __attribute__((constructor)) first_message(void)
{
	printf("You're beat! and yet, you must allow,\nI bore my house upon my back!\n");
}
