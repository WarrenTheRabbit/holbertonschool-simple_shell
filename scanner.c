#include "shell.h"

/**
 * initialise_command_array - Tokenizes a line into an array of arguments.
 *
 * @line: The input line to be tokenized.
 * @args: An array to store the tokenized arguments.
 * @max_args: The maximum number of arguments the array can hold.
 *
 * Description:
 * This function tokenizes the input line into separate arguments using
 * space as the delimiter. It populates the 'args' array with the tokenized
 * arguments and ensures proper null termination for exec call.
 */

void initialise_command_array(char *line, char *cp_line, char *args[], int max_args)
{
	int arg_count = 0;
	char *token;

	if (line == NULL)
		return;
	token = strtok(cp_line, " ");

	while (token != NULL && arg_count < max_args - 1)
	{
		args[arg_count++] = token;
		token = strtok(NULL, " ");
	}
	/* NULL terminate array for exec call. */
	args[arg_count] = NULL;
}

void modify_command_array(char *line, char *args[], int *memory_allocated)
{
	char *path;
	if (line == NULL || strlen(line) == 0 || strcmp(line, "env") == 0)
	{
		return;
	}

	path = find_executable(line);
	if (path != NULL)
	{
		strcpy(line, path);
		args[0] = path; /* need to free */
		*memory_allocated = 1;
	}
	else
	{
		strcpy(line, args[0]);
	}
}
