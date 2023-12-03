#include "main.h"

#define BUFFER_SIZE 1024

/**
 * error_exit - handles error cases and exits
 * @code: error code
 * @message: error message format string
 * @file_name: name of the file causing the error
 * @fd: file descriptor value
 *
 * This function prints an error message, closes file descriptors if needed,
 * and exits the program with the provided error code.
 */
void error_exit(int code, char *message, char *file_name, int fd) {
    dprintf(STDERR_FILENO, message, file_name);
    if (fd != -1)
        close(fd);
    exit(code);
}

/**
 * copy_file - copies content from one file to another
 * @file_from: source file
 * @file_to: destination file
 *
 * This function copies the content of file_from to file_to.
 * It handles errors according to the guidelines provided.
 */
void copy_file(const char *file_from, const char *file_to) {
    int fd_from, fd_to, bytes_read, bytes_written;
    char buffer[BUFFER_SIZE];
    mode_t prev_umask;

    fd_from = open(file_from, O_RDONLY);
    if (fd_from == -1)
        error_exit(98, "Error: Can't read from file %s\n", (char *)file_from, -1);

    prev_umask = umask(0);
    fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    umask(prev_umask);

    if (fd_to == -1)
        error_exit(99, "Error: Can't write to %s\n", (char *)file_to, fd_from);

    if (fchmod(fd_to, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH) == -1) {
        error_exit(99, "Error: Can't set permissions for %s\n", (char *)file_to, fd_from);
    }
    while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(fd_to, buffer, bytes_read);
        if (bytes_written == -1)
            error_exit(99, "Error: Can't write to %s\n", (char *)file_to, fd_from);

        if (bytes_written != bytes_read) {
            error_exit(99, "Error: Can't write to %s\n", (char *)file_to, fd_from);
        }
    }

    if (bytes_read == -1)
        error_exit(98, "Error: Can't read from file %s\n", (char *)file_from, fd_from);

    if (close(fd_from) == -1 || close(fd_to) == -1)
        error_exit(100, "Error: Can't close fd\n", "", -1);
}

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * This function checks the number of arguments, and if valid,
 * copies content from one file to another using copy_file function.
 * It handles errors according to the guidelines provided.
 *
 * Return: 0 on success, otherwise error codes based on specific failures.
 */
int main(int argc, char *argv[]) {
    if (argc != 3) {
        dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
        exit(97);
    }

    copy_file(argv[1], argv[2]);

    return 0;
}

