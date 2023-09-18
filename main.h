#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#ifndef MAIN_H
#define MAIN_H

extern char **environ; /* declare environ */

void parse(char* input, char** args);
int is_interactive(void);
void execute_command(char** args);

#endif

