#include "main.h"

#define BUFFER_SIZE 1024

/**
 * print_error - Prints error messages based on code and file descriptor status
 * @code: Error code to exit with
 * @message: Error message to display
 * @file_name: Name of the file causing the error
 * @fd: File descriptor value (-1 if not applicable)
 *
 * Description: This function prints error messages to the standard error based on
 * the provided error code, error message, file name, and file descriptor status.
 */
void print_error(int code, const char *message, const char *file_name, int fd) {
dprintf(STDERR_FILENO, "%s: %s %s", message, file_name, fd >= 0 ? "fd" : "");
    if (fd >= 0) dprintf(STDERR_FILENO, "%d", fd);
    dprintf(STDERR_FILENO, "\n");
    exit(code);
}

/**
 * copy_file - Copies content from one file to another
 * @file_from: Source file to copy from
 * @file_to: Destination file to copy to
 *
 * Description: This function copies the content of file_from to file_to. It uses
 * a buffer to read data from file_from and writes it to file_to in chunks of
 * BUFFER_SIZE until the entire file is copied.
 * Additionally, it handles various error scenarios as specified.
 */
void copy_file(const char *file_from, const char *file_to) {
    int fd_from, fd_to, bytes_read, bytes_written;
    char buffer[BUFFER_SIZE];

    fd_from = open(file_from, O_RDONLY);
    if (fd_from == -1) {
        print_error(98, "Error: Can't read from file", file_from, -1);
    }

    fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_to == -1) {
        print_error(99, "Error: Can't write to file", file_to, -1);
    }

    while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(fd_to, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            print_error(99, "Error: Can't write to file", file_to, fd_to);
        }
    }

    if (bytes_read == -1) {
        print_error(98, "Error: Can't read from file", file_from, fd_from);
    }

    if (close(fd_from) == -1) {
        print_error(100, "Error: Can't close fd", file_from, fd_from);
    }

    if (close(fd_to) == -1) {
        print_error(100, "Error: Can't close fd", file_to, fd_to);
    }
}


/**
 * error_file - Checks if files can be opened and handles errors
 * @file_from: File descriptor for source file
 * @file_to: File descriptor for destination file
 * @argv: Arguments vector
 *
 * Description: This function checks if files can be opened. If any file cannot be
 * opened, it prints an error message and exits with the respective error code.
 */
void error_file(int file_from, int file_to, char *argv[]) {
    if (file_from == -1) {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }
    if (file_to == -1) {
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
        exit(99);
    }
}

/**
 * main - Entry point, copies content from one file to another
 * @argc: Number of arguments passed to the program
 * @argv: Array of arguments passed to the program
 *
 * Description: The main function checks for the correct number of arguments and
 * then calls the copy_file function to copy the content of one file to another.
 * If the number of arguments is incorrect, it prints an error message and exits.
 *
 * Return: Upon successful execution, returns 0. Otherwise, returns an error code.
 */
int main(int argc, char *argv[]) {
    int file_from, file_to, err_close;
    ssize_t nchars, nwr;
    char buf[BUFFER_SIZE];

    if (argc != 3) {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        return 97;
    }

    file_from = open(argv[1], O_RDONLY);
    if (file_from == -1) {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        return 98;
    }

    file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
    error_file(file_from, file_to, argv);

    while ((nchars = read(file_from, buf, BUFFER_SIZE)) > 0) {
        nwr = write(file_to, buf, nchars);
        if (nwr == -1) {
            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
            return 99;
        }
    }

    if (nchars == -1) {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        return 98;
    }

    err_close = close(file_from);
    if (err_close == -1) {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
        return 100;
    }

    err_close = close(file_to);
    if (err_close == -1) {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
        return 100;
    }

    return 0;
}
