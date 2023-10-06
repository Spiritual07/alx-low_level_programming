#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TOK_DELIM " \t\r\n\a\""

char **split_string(char *str)
{
	int buf_size = 64;
	char *token;
	char **arr_w;
	int x = 0;

	arr_w = malloc(sizeof(char *) * buf_size);
	if (arr_w == NULL)
	{
		fprintf(stderr, "Error allocating memory\n");
		exit(98);
	}
	token = strtok(str, TOK_DELIM);
	while (token != NULL)
	{
		if (token[0] == '#')
		{
			break;
		}
		if (x == buf_size - 1)
		{
			buf_size += buf_size;
			arr_w = realloc(arr_w, sizeof(char *) * buf_size);
			if (arr_w == NULL)
			{
				fprintf(stderr, "Error reallocating memory\n");
				exit(98);
			}
		}
		arr_w[x] = malloc(sizeof(char) * strlen(token) + 1);
		strcpy(arr_w[x], token);
		x++;
		token = strtok(NULL, TOK_DELIM);
	}
	arr_w[x] = NULL;
	return (arr_w);
}

int main() {
    char str[] = "Hello, how are you?";
    char** words;
	int i;

	words = split_string(str);

    for (i = 0; words[i] != NULL; i++) {
        printf("%s\n", words[i]);
        free(words[i]);  // Free each word when done
    }
    free(words);  // Free the array when done

    return 0;
}
