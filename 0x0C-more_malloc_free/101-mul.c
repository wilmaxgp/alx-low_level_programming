#include "main.h"

/**
 * multiply - program that multiplies two positive numbers.
 * Description: program that multiplies two positive numbers.
 * @num1: A string representing the first positive number.
 * @num2: A string representing the second positive number.
 * @result: A character array to store the result of the multiplication.
 *
 * Return: void
 */
void multiply(const char* num1, const char* num2, char* result) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int len3 = len1 + len2;
    int i, j;
    int* prod = calloc(len3, sizeof(int));
    int offset;

    for (i = len1 - 1; i >= 0; i--) {
        for (j = len2 - 1; j >= 0; j--) {
            int digit1 = num1[i] - '0';
            int digit2 = num2[j] - '0';
            int sum = prod[i + j + 1] + (digit1 * digit2);
            prod[i + j + 1] = sum % 10;
            prod[i + j] += sum / 10;
        }
    }

    offset = 0;
    while (offset < len3 - 1 && prod[offset] == 0) {
        offset++;
    }

    for (i = offset, j = 0; i < len3; i++, j++) {
        result[j] = prod[i] + '0';
    }
    result[len3 - offset] = '\0';

    free(prod);

}


int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Error\n");
        return 98;
    }

    const char* num1 = argv[1];
    const char* num2 = argv[2];

    int i;
    for (i = 0; i < strlen(num1); i++) {
        if (num1[i] < '0' || num1[i] > '9') {
            printf("Error\n");
            return 98;
        }
    }

    for (i = 0; i < strlen(num2); i++) {
        if (num2[i] < '0' || num2[i] > '9') {
            printf("Error\n");
            return 98;
        }
    }

    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int len3 = len1 + len2 + 1;
    char* result = malloc(len3 * sizeof(char));

    multiply(num1, num2, result);
    printf("%s\n", result);

    free(result);
    return 0;
}
