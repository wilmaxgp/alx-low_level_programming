#include "main.h"

/**
 * isPositiveInteger - checks if it is a postive integer.
 * Description: check it it is a positive numbers.
 * @str: string input
 *
 * Return: void
 */
int isPositiveInteger(const char *str)
{
	int i;
	int len = strlen(str);

	if (len == 0)
		return (0);

	for (i = 0; i < len; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}

	return (1);
}
/**
 * multiply - program that multiplies two positive numbers.
 * Description: program that multiplies two positive numbers.
 * @num1: 1st number input
 * @num2: 2nd number input
 *
 * Return: void
 */
void multiply(const char *num1, const char *num2)
{
	int i, j, len1, len2, len;
	int *result;

	len1 = strlen(num1);
	len2 = strlen(num2);
	len = len1 + len2;
	
	result = (int *)malloc(sizeof(int) * len);
	if (result == NULL)
	{
		printf("Error\n");
		exit(98);
	}

	for (i = 0; i < len; i++)
	{
		result[i] = 0;
	}

	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			int digit1 = num1[i] - '0';
			int digit2 = num2[j] - '0';
			int product = digit1 * digit2;
			int sum = result[i + j + 1] + product;

			result[i + j] += sum / 10;
			result[i + j + 1] = sum % 10;
		}
	}

	i = 0;
	while (i < len - 1 && result[i] == 0)
	{
		i++;
	}

	for (; i < len; i++)
	{
		printf("%d", result[i]);
	}
	printf("\n");

	free(result);
}
/**
 * main - program that multiplies two positive numbers.
 * Description: program that multiplies two positive numbers.
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: void
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	if (!isPositiveInteger(argv[1]) || !isPositiveInteger(argv[2]))
	{
		printf("Error\n");
		return (98);
	}

	multiply(argv[1], argv[2]);


	return (0);
}

