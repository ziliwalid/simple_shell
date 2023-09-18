#include "main.h"


/* constants */
#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 100

int is_interactive(void);

int main(void)
{
	char input[MAX_INPUT_SIZE];
	char* args[MAX_ARG_SIZE];
	char **env = environ;
	int is_interactive_mode = is_interactive();
	
	while (1) 
	{
		if (is_interactive_mode) 
		{
			printf("($) ");
			fflush(stdout);
		}
		if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) 
		{
			/* handle end of file case (ctrl+d) */
			break;
		}
		/* remove newline character */
		input[strcspn(input, "\n")] = '\0';
		if(strcmp(input, "exit") == 0)
			break;/* this is is to exit the program once we type exit */
		if (strcmp(input, "env") == 0) 
		{
			/* print env vars */
			while (*env)
			{
				printf("%s\n", *env);
				env++;
			}
		}
		else 
		{
			parse(input, args);
			execute_command(args);
		}
	}
	return (0);
}

int is_interactive(void)
{
	return (isatty(STDIN_FILENO));
}
