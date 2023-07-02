#include "main.h"


/**
 * argstostr - concartenates all the arguments
 * Description: function that concatenates all the arguments of your program
 * @ac: an integer representing the number of arguments passed to the program
 * @av: an argument vector
 *
 * Return: void
 */
char *argstostr(int ac, char **av)
{
	char *str;
	int total_length = 0, i, j, k = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
			total_length++;
		total_length++;
	}

	str = malloc(sizeof(char) * (total_length + 1));
	if (str == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++, k++)
			str[k] = av[i][j];
		str[k] = '\n';
		k++;
	}
	str[k] = '\0';

	return str;
}

