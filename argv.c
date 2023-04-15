#include <stdio.h>

/**
 * main - function built-in
 * @argc: number of arguments
 * @argv: actual arguments passed
 *
 * Return: 0 sucess
 */

int main(int argc, char *argv[])
{
	int i;

	printf("Number of arguments: %d\n", argc);
	for (i = 0; i < argc; i++)
	{
		printf("Argument %d: %s\n", i, argv[i]);
	}
	return (0);
}
