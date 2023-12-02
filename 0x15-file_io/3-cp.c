#include "main.h"

#define BUFFER_SIZE 1024
#define PERMISSIONS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)

/**
 * error_exit - Print error message and exit
 * @err_code: Error code
 * @msg: Error message
 */
void error_exit(int err_code, const char *msg)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(err_code);
}

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
		error_exit(97, "Usage: cp file_from file_to");

	fd_from = open(argv[1], O_RDONLY);

	if (fd_from == -1)
	{
		char error_msg[256];
		snprintf(error_msg, sizeof(error_msg), "Error: Can't read from file %s", argv[1]);
		error_exit(98, error_msg);
	}

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, PERMISSIONS);

	if (fd_to == -1)
	{
		char error_msg[256];
		snprintf(error_msg, sizeof(error_msg), "Error: Can't write to %s", argv[2]);
		error_exit(99, error_msg);
	}

	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written != bytes_read)
		{
			char error_msg[256];
			snprintf(error_msg, sizeof(error_msg), "Error: Can't write to %s", argv[2]);
			error_exit(99, error_msg);
		}
	}

	if (bytes_read == -1)
	{
		char error_msg[256];
		snprintf(error_msg, sizeof(error_msg), "Error: Can't read from file %s", argv[1]);
		error_exit(98, error_msg);
	}

	if (close(fd_from) == -1)
	{
		char error_msg[256];
		snprintf(error_msg, sizeof(error_msg), "Error: Can't close file descriptor for %s", argv[1]);
		error_exit(100, error_msg);
	}

	if (close(fd_to) == -1)
	{
		char error_msg[256];
		snprintf(error_msg, sizeof(error_msg), "Error: Can't close file descriptor for %s", argv[2]);
		error_exit(100, error_msg);
	}

	return (0);
}
