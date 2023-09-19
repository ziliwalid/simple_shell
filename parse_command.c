#include "main.h"

/**
  * parse - tokenizes provided input into an array of strings
  * @input: string param containing the command
  * @args: args param that points to an array of strings
  * Return: void, nadaaaa :)
  */

void parse(char *input, char **args)
{
	int i = 0;
	char *token = strtok(input, " \n\t");

	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " \n\t");
	}
	args[i] = NULL;
}
