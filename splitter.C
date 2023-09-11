#include "main.h"

char **commandeSplitter(char *str)
{
    char *token;
    char **tokens = NULL;
    int i = 0; /*indexing*/

    token = strtok(str, "\t\n");
    while(token != NULL)
    {
        i++;
        tokens == realloc(tokens, i * sizeof(char *));
        if (tokens == NULL)
        {
            perror("realloc");
            exit(EXIT_FAILURE);
        }
        tokens[i - 1] = token;
        token = strtok(NULL, "\t\n");
    }
    for(i=0; tokens[i]; i++)
    {
        printf("%s\n", tokens[i]);
    }
    return(tokens);
}
