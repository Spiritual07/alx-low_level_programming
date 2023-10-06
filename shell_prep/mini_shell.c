#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

char **get_input(char *);

int main() {
    extern char **environ;
    char **command;
    char *input = NULL;
    pid_t child_pid;
    int stat_loc;
    ssize_t read;
    size_t len = 0;

    while (1) {
        printf("$");
        read = getline(&input, &len, stdin);
        if (read == -1) {
            perror("getline failed");
            break;
        }
        input[strcspn(input, "\n")] = 0;
        command = get_input(input);

        if (!command[0]) {      /* Handle empty commands */
            free(input);
            free(command);
            continue;
        }

        /* Handle built-in commands */
        if (strcmp(command[0], "cd") == 0) {
            if (chdir(command[1]) < 0) {
                perror("cd failed");
            }
            continue;
        } else if (strcmp(command[0], "ls") == 0) {
            system("ls");
            continue;
        }

        child_pid = fork();
        if (child_pid < 0) {
            perror("fork failed");
            exit(EXIT_FAILURE);
        }
        if (child_pid == 0) {
            if (execve(command[0], command, environ) == -1) {
                perror("execve failed");
                exit(EXIT_FAILURE);
            }
        } else {
            if (waitpid(child_pid, &stat_loc, WUNTRACED) == -1) {
                perror("waitpid failed");
                exit(EXIT_FAILURE);
            }
        }

        free(input);
        free(command);
    }

    return 0;
}

char **get_input(char *input) {
    size_t size = 8;
    char **command = malloc(size * sizeof(char *));
    char *separator = " ";
    char *parsed;
    size_t index = 0;

    if (!command) {
        fprintf(stderr, "get_input: allocation error\n");
        exit(EXIT_FAILURE);
    }

    parsed = strtok(input, separator);
    while (parsed != NULL) {
        if (index >= size) {
            size *= 2;
            command = realloc(command, size * sizeof(char *));
            if (!command) {
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
