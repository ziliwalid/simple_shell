#include "main.h"

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



/**
 * main - Entry point
 * Return: Int
 */  

int main(int argc, char **argv)
 {
        (void)argc;
         (void)argv;

        char *buffer = NULL, **tokens;
        size_t size_buffer = 0;
         int n_char = 0;
         int i = 0;
        int token_size = 0;

        write(1, "$ " ,2);
         n_char = getline(&buffer, &size_buffer, stdin);
       if (n_char == -1)
          {
                 perror("getline");
                exit(EXIT_FAILURE);
        }
        buffer[n_char - 1] = '\0';
         tokens = commandeSplitter(buffer);
        return (0);
 }

