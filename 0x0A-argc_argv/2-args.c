#include "main.h"

/*
 * print_arguments - Prints all the arguments received.
 * Description: Prints all the arguments received
 * @argc: The total number of arguments.
 * @argv: An array of strings representing the arguments.
 *
 * Return: void
 */
void print_arguments(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}
}

/*
 * main - Entry point
 * Description: Entry point of the program
 * @argc: The total number of arguments.
 * @argv: An array of strings representing the arguments.
 *
 * Return: void
 */
int main(int argc, char *argv[])
{
	print_arguments(argc, argv);

	return (0);
}

