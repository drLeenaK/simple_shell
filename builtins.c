#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/**
 * token_interface - tokenize a string
 * @line: string to be tokenized
 * @delim: delimiter used for tokenization
 * @token_count: pointer to the number of tokens
 *
 * Return: array of tokens
 */

char **token_interface(char *line, const char *delim, int *token_count)
{
	char **tokens;
	char *token;
	int i;

	tokens = malloc(sizeof(char *) * 1024);
	if (tokens == NULL)
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, delim);
	for (i = 0; token != NULL; i++)
	{
		tokens[i] = token;
		token = strtok(NULL, delim);
	}
	tokens[i] = NULL;
	*token_count = i;

	return (tokens);
}

/**
 * cd_b - changes the current working directory
 *      if no parameter is passed it will change directory to HOME.
 * @line: string representing the input
 */

void cd_b(char *line)
{
	int index;
	int token_count;
	char **param_array;
	const char *delim = "\n\t ";

	char **token_interface(char *line, const char *delim, int *token_count);

	token_count = 0;
	param_array = token_interface(line, delim, &token_count);

	if (param_array[0] == NULL)
	{
		double_free(param_array);
		return;
	}

	if (param_array[1] == NULL)
	{
		index = find_path("HOME");
		chdir((environ[index]) + 5);
	}
	else if (_strcmp(param_array[1], "-") == 0)
		printf("%s\n", param_array[1]);
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

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
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
	exit(0);
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
