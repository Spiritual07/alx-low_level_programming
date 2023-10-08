#include "shell.h"

/* Function to execute a command */
void executeCommand(char **command) {
    /* Get the PATH environment variable */
    char *path = getenv("PATH");
    /* Duplicate the PATH string */
    char *path_copy = strdup(path);
    /* Split the PATH into directories */
    char *dir = strtok(path_copy, ":");

    /* For each directory in the PATH */
    while (dir != NULL) {
        /* Allocate memory for the command path */
        char *cmd_path = malloc(strlen(dir) + strlen(command[0]) + 2);
        /* Copy the directory to the command path */
        strcpy(cmd_path, dir);
        /* Append a slash to the command path */
        strcat(cmd_path, "/");
        /* Append the command to the command path */
        strcat(cmd_path, command[0]);

        /* Execute the command */
        execv(cmd_path, command);
        /* If executing the command failed for a reason other than the command not being found, print an error and exit */
        if (errno != ENOENT) {
            perror(cmd_path);
            exit(EXIT_FAILURE);
        }

        /* Free the memory allocated for the command path */
        free(cmd_path);
        /* Get the next directory from the PATH */
        dir = strtok(NULL, ":");
    }

    /* If the command was not found in any directory, print an error and exit */
    fprintf(stderr, "%s: command not found\n", command[0]);
    exit(EXIT_FAILURE);
}

