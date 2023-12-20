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

void print_bin_command(char **args)
{
	char buffer[256];
	int counter;

	counter = 0;
	if (args[counter + 1] != NULL)
	{
		while (args[counter])
		{
			if (args[counter + 1])
			{
				snprintf(buffer, 256, "%s %s", args[counter], args[counter + 1]);
			}
			counter = counter + 1;
		}
		system(buffer);
	}
	else
	{
		system(args[0]);
	}
}
