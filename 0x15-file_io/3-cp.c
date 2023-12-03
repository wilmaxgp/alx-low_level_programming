#include "main.h"

#define BUFFER_SIZE 1024

/**
 * error_exit - handles error cases and exits
 * @code: error code
 * @message: error message format string
 *
 * This function prints an error message and exits the program with
 * the provided error code.
 */
void error_exit(int code, const char *message)
{
    dprintf(STDERR_FILENO, "%s\n", message);
    exit(code);
}

/**
 * main - copies content of one file to another
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, otherwise error codes based on specific failures.
 */
int main(int argc, char *argv[])
{
    int file_from, file_to;
    ssize_t nchars, nwr;
    char buf[BUFFER_SIZE];

    if (argc != 3)
        error_exit(97, "Usage: cp file_from file_to");

    file_from = open(argv[1], O_RDONLY);
    if (file_from == -1)
        error_exit(98, "Error: Can't read from file");

    file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
    if (file_to == -1)
        error_exit(99, "Error: Can't write to file");

    while ((nchars = read(file_from, buf, BUFFER_SIZE)) > 0)
    {
        nwr = write(file_to, buf, nchars);
        if (nwr != nchars)
            error_exit(99, "Error: Can't write to file");
    }

    if (nchars == -1)
        error_exit(98, "Error: Can't read from file");

    if (close(file_from) == -1 || close(file_to) == -1)
        error_exit(100, "Error: Can't close file");

    return 0;
}

