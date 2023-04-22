#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/**
 * cd_b - changes the current working directory
 * 	if no parameter is passed it will change directory to HOME.
 * @line: string representing the input
 */

void cd_b(char *line)
{
	int index;
	int token_count;
	char **param_array;
	const char *delim = "\n\t ";
	char **token_interface(char *line, const char *delim, int token_count);

	token_count = 0;
	param_array = token_interface(line, delim, token_count);

	if (param_array[0] == NULL)
	{
		single_free(2, param_array, line);
		return;
	}
	if (param_array[1] == NULL)
	{
		index = find_path("HOME");
		chdir((environ[index]) + 5);
	}
	else if (_strcmp(param_array[1], "-") == 0)
		print_str(param_array[1], 0);

	else
		chdir(param_array[1]);
	double_free(param_array);
}

/**
 * env_b - environmental variables
 * @line: name of function needed.
 *
 * Return: nothing
 */

void env_b(__attribute__((unused))char *line)
{
	int i;
	int j;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '\0'; j++)
			write(STDOUT_FILENO, &environ[i][j], 1);
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * exit_b - frees malloc and exit shell
 * @line: name of function needed.
 *
 * Return: nothing.
 */
void exit_b(char *line)
{
	free(line);
	print_str("\n", 1);
	exit(1);
}

/**
 * check_built_ins - finds function needed for execution.
 * @str: name of function needed.
 *
 * Return: NULL if failed
 */
void (*check_built_ins(char *str))(char *str)
{
	int i;

	builtin_t buildin[] = {
		{"exit", exit_b},
		{"env", env_b},
		{"cd", cd_b},
		{NULL, NULL}
	};

	for (i = 0; buildin[i].built != NULL; i++)
	{
		if (_strcmp(str, buildin[i].built) == 0)
		{
			return (buildin[i].f);
		}
	}
	return (NULL);
}

/**
 * built_in - builtin functions checker
 * @command: holds all arguments passed by the user
 * @line: holds user input strings
 *
 * Return: 0 for success, -1 for failure
 */
int built_in(char **command, char *line)
{
	void (*build)(char *);

	build = check_built_ins(command[0]);
	if (build == NULL)
		return (-1);
	if (_strcmp("exit", command[0]) == 0)
		double_free(command);
	build(line);
	return (0);
}
