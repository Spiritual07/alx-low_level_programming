#include "main.h"

/**
 * create_file - function that creates a file.
 * @filename: name of file
 * @text_content: content of file
 * Return: 1 on success, -1 on failure (file can not be created,
 * file can not be written, write “fails”, etc…)
 */

int create_file(const char *filename, char *text_content)
{
	int fileDes, len;

	if (filename == NULL)
	{
		return (-1);
	}
	fileDes = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fileDes == -1)
	{
		return (-1);
	}
	if (text_content != NULL)
	{
		len = strlen(text_content);
		if (write(fileDes, text_content, len) != len)
		{
			close(fileDes);
			return (-1);
		}
	}
	close(fileDes);
	return (1);
}
