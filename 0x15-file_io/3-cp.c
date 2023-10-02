#include "main.h"

/**
 * main - program that copies the content of a file to another file.
 * @ac: arguments counts
 * @av: arguments vector(input strings)
 * Return: 0 (success);
 * Description: Usage: cp file_from file_to
 */

int main(int ac, char *av[])
{
	int file_from, file_to, read_size;
	char buffer[1024];

	if (ac != 3)
	{
		dprintf(2, "Usage: cp file_from file_to\n"), exit(97);
	}
	file_from = open(av[1], O_RDONLY);
	if (file_from < 0)
	{
		dprintf(2, "Error: Can't read from file %s\n", av[1]), exit(98);
	}
	file_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (file_to < 0)
	{
		dprintf(2, "Error: Can't write to %s\n", av[2]), exit(99);
	}
	while ((read_size = read(file_from, buffer, 1024)) > 0)
	{
		if (write(file_to, buffer, read_size) != read_size)
		{
			dprintf(2, "Error: Can't write to %s\n", av[2]), exit(99);
		}
	}
	if (read_size < 0)
	{
		dprintf(2, "Error: Can't read from file %s\n", av[1]), exit(98);
	}
	if (close(file_from) < 0)
	{
		dprintf(2, "Error: Can't close fd %d\n", file_from), exit(100);
	}
	if (close(file_to) < 0)
	{
		dprintf(2, "Error: Can't close fd %d\n", file_to), exit(100);
	}

	return (0);
}
