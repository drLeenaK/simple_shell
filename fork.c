#include "shell.h"

/**
 * fork_process - a system call that creates a new process
 * by duplicating the calling process
 * Return:  process ID (pid) as success
 */

pid_t fork_process(void)
{
	pid_t pid;

	pid = fork();

	if (pid == -1)
	{
		fprintf(stderr, "Error: %s\n", strerror(errno));
	}

	return (pid);
}
