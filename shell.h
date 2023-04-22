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
<<<<<<< HEAD
char **setup_environment(void);
char *path_finder(char *command);
int find_path(char *str);
char **tokenize_path(int index, char *str);
char *search_directories(char **path_tokens, char *command);
char *build_path(char *directory, char *command);
=======
>>>>>>> 98c6d15d09e4e9e2eab8c03254efeb428598d751

#endif

