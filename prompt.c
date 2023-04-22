#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv, char **envp)
{
	char buffer[BUFFER_SIZE];
	char *lees;

	while (1)
	{
		printf("$ ");
		fgets(buffer, BUFFER_SIZE, stdin);

		if (feof(stdin))
		{
			break;
		}

		buffer[strcspn(buffer, "n")] = '0';

		lees = strtok(buffer, " ");

		if (lees == NULL)
		{
			continue;
		}

		if (execve(lees, argv, envp) == -1)
		{
			printf("Error: command not foundn");
		}
	}

	return 0;
}
