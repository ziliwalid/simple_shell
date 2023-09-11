#include "main.h"

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
