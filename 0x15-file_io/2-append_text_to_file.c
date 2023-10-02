#include "main.h"

/**
 * append_text_to_file - function that appends text at the end of a file.
 * @filename:  name of the file
 * @text_content: the NULL terminated string to add at the end of the file
 * Return: 1 on success and -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fileDes, writeRes, len = 0;

	if (filename == NULL)
	{
		return (-1);
	}
	fileDes = open(filename, O_WRONLY | O_APPEND);
	if (fileDes == -1)
	{
		return (-1);
	}
	if (text_content == NULL)
	{
		close(fileDes);
		return (1);
	}
	if (text_content != NULL)
	{
		while (text_content[len])
		{
			len++;
		}
		writeRes = write(fileDes, text_content, len);
		if (writeRes == -1)
		{
			return (-1);
		}
	}
	close(fileDes);
	return (1);
}
