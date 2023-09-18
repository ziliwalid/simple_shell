#include "main.h"

void parse(char *input, char **args)
{
	int i = 0;
	char* token = strtok(input, " \n\t");
	
	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " \n\t");
	}
	args[i] = NULL;
}
