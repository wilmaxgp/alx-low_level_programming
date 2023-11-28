#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 * @filename: The name of the file to read
 * @letters: Number of letters to read and print
 *
 * Return: Number of letters it could read and print, or 0 on failure
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	FILE *file;
	char buffer[1024];
	ssize_t total_read = 0;
	ssize_t bytes_read;
	ssize_t bytes_written;


	if (filename == NULL)
		return (0);

	file = fopen(filename, "r");

	if (file == NULL)
		return (0);

	while (letters > 0 &&
			(bytes_read = fread(buffer, sizeof(char),
					    (letters < 1024) ? letters : 1024, file)) > 0)
	{
		bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
		if (bytes_written < 0 || bytes_written != bytes_read)
		{
			fclose(file);
			return (0);
		}
		
		total_read += bytes_read;
		letters -= bytes_read;
	}

	fclose(file);
	return (total_read);
}
