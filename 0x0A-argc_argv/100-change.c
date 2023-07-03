#include "main.h"

/**
 * main - Entry point of the program
 * Description: This function calculates the minimum number of coins
 * required to make change for a given amount of money.
 * @argc: The number of command-line arguments (including the program name).
 * @argv: An array of strings representing the command-line arguments.
 *
 * Return: 0 on success, 1 on error.
 */
int main(int argc, char *argv[])
{
	int cents;
	int coins[] = {25, 10, 5, 2, 1};
	int num_coins;
	int count;
	int i;

    if (argc != 2) {
        printf("Error\n");
        return 1;
    }

    cents = atoi(argv[1]);

    if (cents < 0) {
        printf("0\n");
        return 0;
    }

    num_coins = sizeof(coins) / sizeof(coins[0]);
    count = 0;

    for (i = 0; i < num_coins; i++) {
        count += cents / coins[i];
        cents %= coins[i];
    }

    printf("%d\n", count);
    return 0;
}

