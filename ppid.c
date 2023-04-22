#include "shell.h"

/**
 * get_ppid - retrieve the process ID of the current process's parent
 * Return: 0 success
 */

pid_t get_ppid(void)
{
	return (getppid());
}
