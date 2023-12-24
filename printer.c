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

