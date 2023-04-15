#ifndef SHELL_H
#define SHELL_H

/* Built-in Libraries */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

/* Global variables */

extern char **environ;

/* Used prototypes */

void print_prompt(void);
char *read_command(void);
char **parse_command(char *command);
int execute_command(char **args);
int check_status(int status);
int wait_for_process(pid_t pid);
pid_t fork_process(void);
pid_t get_pid(void);
pid_t get_ppid(void);
char **setup_environment(void);

#endif

