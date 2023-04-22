#include "shell.h"

/**
 * execute_command - executes the user input
 * @args: the arguments entered by the user
 *
 * Return: 1
 */

int execute_command(char **args)
{
	pid_t pid, wpid;
	int status;

	pid = fork_process();

	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			fprintf(stderr, "Error: %s\n", strerror(errno));
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		fprintf(stderr, "Error: %s\n", strerror(errno));
	}
	else
	{
		wait_for_process(pid);
	}
	return (1);
}
