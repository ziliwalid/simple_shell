#include "main.h"



void execute_command(char **args)
{
	pid_t pid;
	/* Handle the parsed command (args :)) */
	if (args[0] != NULL)
	{
		pid = fork();
		if (pid == 0)
		{
			/* create Child process */
			if (execvp(args[0], args) == -1)
			{
				perror("execvp");
				exit(EXIT_FAILURE);
			}
		}
		else if (pid < 0)
		{
			perror("fork");
		}
		else
		{
			/* handling parent process */
			wait(NULL);
		}
	}
}
