#include "main.h"

/**
 * read_textfile -  function that reads a text file and prints it
 * to the POSIX standard output.
 * @filename: name of the file
 * @letters: the number of letters it should read and print
 * Return: actual number of letters it could read and print
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fileDes;
	char *buff;
	ssize_t bytesRead, bytesWritten;

	if (filename == NULL)
	{
		return (0);
	}
	fileDes = open(filename, O_RDONLY);
	if (fileDes == -1)
	{
		return (0);
	}
	buff = malloc(letters);
	if (buff == NULL)
	{
		close(fileDes);
		return (0);
	}
	bytesRead = read(fileDes, buff, letters);
	if (bytesRead == -1)
	{
		free(buff);
		close(fileDes);
		return (0);
	}
	bytesWritten = write(1, buff, bytesRead);
	if (bytesWritten == -1 || bytesWritten != bytesRead)
	{
		free(buff);
		close(fileDes);
		return (0);
	}
	free(buff);
	close(fileDes);

	return (bytesWritten);
}
