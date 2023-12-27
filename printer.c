#include "shell.h"

/**
 * print_prompt - Prints the shell prompt.
 */
void print_prompt(void)
{
	printf("$ ");
}

/**
 * print_command_not_found_error - Prints an error message for a command
 * not found.
 * @str: The command that was not found.
 */
void print_command_not_found_error(char *str)
{
	printf("hash: %s :command not found\n", str);
}

/**
 * print_not_found_error - Prints an error message for a command not found.
 * @str: The command that was not found.
 */
void print_not_found_error(char *str, char *exe_name)
{
	fprintf(stderr, "%s: 1: %s: not found\n", exe_name, str);
}

/**
 * printenv_with_environ - Prints the environment variables.
 */
void printenv_with_environ(void)
{
	char **cp_environ;

	cp_environ = environ;

	while (*cp_environ != NULL)
	{
		printf("%s\n", *cp_environ);
		cp_environ++;
	}
}
