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

/**
 * print_bin_command - call print_bin_command
 * @args: args from initialise_command_array
 */

void print_bin_command(char **args)
{
	char buffer[256];
	int counter;
	char flags[128], temp_flags[128];

	counter = 0;

	if (args[counter + 1] != NULL)
	{
		strcpy(flags, args[counter + 1]);
		strcpy(temp_flags, args[counter + 1]);
		while (args[counter + 1])
		{
			if (args[counter + 2])
			{
				snprintf(flags, 128, "%s %s", temp_flags, args[counter + 2]);
				strcpy(temp_flags, flags);
			}
			counter = counter + 1;
		}
		snprintf(buffer, 256, "%s %s", args[0], flags);
		system(buffer);
	}
	else
	{
		system(args[0]);
	}
}
