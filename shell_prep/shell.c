#include "shell.h"

/* Function to process user input */
char *processInput(size_t *len)
{
    char *input = NULL;
    ssize_t read;

    read = getline(&input, len, stdin);
    if (read == -1)
    {
        if (feof(stdin))
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

/* Function to execute command */
void executeCommand(char **command, char **environ, char *argv[])
{
    pid_t child_pid;
    int stat_loc;

    child_pid = fork();
    if (child_pid < 0)
    {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    if (child_pid == 0)
    {
        if (execve(command[0], command, environ) == -1)
        {
            fprintf(stderr, "%s: No such file or directory\n", argv[0]);
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

    if (!command)
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
            if (!command)
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

int main(int argc, char *argv[], char **environ)
{
    char **command;
    char *input = NULL;
    size_t len = 0;

    while (argc == 1)
    {
		printf("$ ");
        input = processInput(&len);
        command = get_input(input);

        if (command == NULL)
        {
            free(input);
            free(command);
            input = NULL;
            command = NULL;
            continue;
        }

        executeCommand(command, environ, argv);

        free(input);
        free(command);
        input = NULL;
        command = NULL;
    }
    return 0;
}

