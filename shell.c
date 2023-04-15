#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

#define MAX_LEN 256

/**
 * parse_command - parses the command
 * @command: actual command
 * Return: the actual arguments
 */

char **parse_command(char *command)
{
	char **args = malloc(MAX_LEN / 2 + 1);
	int i = 0;

	args[0] = strtok(command, " ");

	while (args[i] != NULL)
		args[++i] = strtok(NULL, " ");

	return (args);
}
