#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - Entry point
 * Return: Int
 */  

int main(int ac, char **av)
{
	(void)ac;
	char *buffer = NULL;
	size_t size_buffer = 0;
	int n_char = 0;
	
	write(1, "user: " ,6);
	n_char = getline(&buffer, &size_buffer, stdin);
	if (n_char == EOF)
	{
		perror("getline");
	}
	buffer[n_char - 1] = '\0';
	printf("%s\n", buffer);
	return (0);
	
}
