#include "main.h"

char **commandeSplitter(char *str)
{
    char *token;
    char **tokens = NULL;
    int i = 0; /* indexing */

    token = strtok(str, "\t\n");
    while (token != NULL)
    {
        i++;
        tokens = realloc(tokens, i * sizeof(char *));
        if (tokens == NULL)
        {
            perror("realloc");
            exit(EXIT_FAILURE);
        }
        tokens[i - 1] = malloc(strlen(token) + 1); // Allocate memory for the token
        if (tokens[i - 1] == NULL)
        {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        strcpy(tokens[i - 1], token); // Copy the token into the allocated memory
        token = strtok(NULL, "\t\n");
    }
    for (int j = 0; j < i; j++)
    {
        printf("%s\n", tokens[j]);
    }
    return tokens;
}

