#include "shell.h"

/**
 * main - built in function
 * Return: 0 success
 */

int main(void)
{
	char command[MAX_LEN];
	char *args[MAX_LEN / 2 + 1];
	int status;

	while (1)
	{
		print_prompt();
	if (fgets(command, MAX_LEN, stdin) == NULL)
	{
		printf("\n");
		break;
	}
	if (command[strlen(command) - 1] == '\n')
	{
		command[strlen(command) - 1] = '\0';
	}

	args[0] = strtok(command, " ");

	int i = 0;

	while (args[i] != NULL)
	{
		args[++i] = strtok(NULL, " ");
	}
	if (execute_command(args) == -1)
	{
		fprintf(stderr, "Error: %s\n", strerror(errno));
	}
	}

	return (0);
}
