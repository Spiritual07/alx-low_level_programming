#include "shell.h"

/* Function to process user input */
char *processInput(size_t *len, FILE *inputFile)
{
    char *input = NULL;
    ssize_t read;

    read = getline(&input, len, inputFile);
    if (read == -1)
    {
        if (feof(inputFile))
        {
            exit(EXIT_SUCCESS);
        }
        else
        {
            perror("getline failed");
            exit(EXIT_FAILURE);
        }
    }
    input[_strcspn(input, "\n")] = 0;

    return input;
}

void executeCommand(char **command, char **environ, char *argv[])
{
    pid_t child_pid;
    int stat_loc;
    char *path, *path_copy, *directory;
    char fullpath[255];
    int command_found = 0;
	int access_result = -1;

    /* If the command is not an absolute path, search the PATH directories */
    if (command[0][0] != '/')
    {
        path = getenv("PATH");
        path_copy = strdup(path); /* Create a copy of the PATH string */
        directory = strtok(path_copy, ":");
        while (directory != NULL)
        {
            strncpy(fullpath, directory, sizeof(fullpath) - 1);
            fullpath[sizeof(fullpath) - 1] = '\0';
            strncat(fullpath, "/", sizeof(fullpath) - strlen(fullpath) - 1);
            strncat(fullpath, command[0], sizeof(fullpath) - strlen(fullpath) - 1);

            /* If the file exists and is executable, run it */
			access_result = access(fullpath, X_OK);
            if (access_result == 0)
            {
                command_found = 1;
                break;
            }
            directory = strtok(NULL, ":");
        }
        free(path_copy); /* Free the copy of the PATH string */
    }
    else
    {
        /* If the command is an absolute path, copy it to fullpath */
        strncpy(fullpath, command[0], sizeof(fullpath) - 1);
        fullpath[sizeof(fullpath) - 1] = '\0';
        if (access_result == 0)
        {
            command_found = 1;
        }
    }

    /* Check if the command exists before calling fork() */
    if (!command_found)
    {
        fprintf(stderr, "%s: 1: %s: not found\n", argv[0], command[0]);
		return;
    }

    /* If the command exists, proceed with fork() */
    child_pid = fork();
    if (child_pid < 0)
    {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    if (child_pid == 0)
    {
        if (execve(fullpath, command, environ) == -1)
        {
            fprintf(stderr, "%s: 1: %s: not found\n", argv[0], command[0]);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        if (waitpid(child_pid, &stat_loc, WUNTRACED) == -1)
        {
            perror("waitpid failed");
            exit(EXIT_FAILURE);
        }
    }
}

/* function to tokenize the input */
char **get_input(char *input)
{
    size_t size = 8;
    char **command = malloc(size * sizeof(char *));
    char *separator = " ";
    char *parsed;
    size_t index = 0;

    if (command == NULL)
    {
        fprintf(stderr, "get_input: allocation error\n");
        exit(EXIT_FAILURE);
    }

    parsed = strtok(input, separator);
    while (parsed != NULL)
        {
        if (index >= size)
                {
            size *= 2;
            command = realloc(command, size * sizeof(char *));
            if (command == NULL)
            {
                fprintf(stderr, "get_input: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
        command[index++] = parsed;
        parsed = strtok(NULL, separator);
    }

    command[index] = NULL;
    return command;
}

int main(int argc, char *argv[], char **env)
{
	FILE *inputFile = stdin;
    char **command;
    char *input = NULL;
    size_t len = 0;
	int x = 0;

	if (argc > 1) 
	{
		inputFile = fopen(argv[1], "r");
        if (inputFile == NULL) 
		{
            perror("Error opening input file");
           	return (EXIT_FAILURE);
        }
    }
    while (argc == 1)
    {
		if (inputFile == stdin)
		{
			c_print("$ ");
		}
        input = processInput(&len, inputFile);
        command = get_input(input);

        if (command == NULL)
        {
            free(input);
            free(command);
            input = NULL;
            command = NULL;
            continue;
        }
		if (strcmp(command[0], "env") == 0)
    	{
        	while (env[x])
        	{
            	printf("%s\n", env[x++]);
        	}
        	continue;
    	}
		if (strcmp(command[0], "exit") == 0)
    	{
        	free(input);
        	free(command);
        	if (inputFile != stdin)
            fclose(inputFile);
        	exit(EXIT_SUCCESS);
    	}

        executeCommand(command, env, argv);

        free(input);
        free(command);
        input = NULL;
        command = NULL;

		if (inputFile != stdin && feof(inputFile))
			break;
    }
	if (inputFile != stdin)
    fclose(inputFile);
    
	return 0;
}


/**
 * c_print - function to print to output
 * @str: string to print
 */

void c_print(char *str)
{
	write(STDOUT_FILENO, str, _strlen(str));
}

/**
 * _strlen - function that returns the length of a string.
 * @s: str to return it's length.
 * Return: integer (string length)
 */

int _strlen(char *s)
{
        int x, count = 0;

        for (x = 0; s[x] != '\0'; x++)
        {
                count++;
        }
        return (count);
}

