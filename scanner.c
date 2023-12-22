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

void initialise_command_array(char *line, char *args[], int max_args)
{
	int arg_count = 0;
	char *token, *first_string = strdup(line);
	int is_bin;
	char *bin_command;
	int hit_bin_command = 0;
	char *tmp;

	if (line == NULL)
		return;

	get_first_string(first_string, ' ');
	is_bin = has_bin_command(first_string);
	bin_command = NULL;
	token = strtok(line, " ");
	while (token != NULL && arg_count < max_args - 1)
	{
		if (arg_count == 0 && is_bin)
		{
			bin_command = malloc(strlen("/bin/") + strlen(token) + 1);
			if (bin_command == NULL)
			{
				free(first_string);
				return;
			}
			snprintf(bin_command, strlen("/bin/") + strlen(token) + 1, "%s%s", "/bin/", token);
			args[arg_count++] = bin_command;
			hit_bin_command = 1;
		}
		else
		{
			args[arg_count++] = token;
		}

		token = strtok(NULL, " ");
	}
	free(first_string);
	if (hit_bin_command)
	{
		if (arg_count > 1)
		{
			tmp = malloc(20);
			strcpy(tmp, strdup(args[1]));
			args[1] = tmp;
		}
		strcpy(line, bin_command);
	}
	/* NULL terminate array for exec call. */
	args[arg_count] = NULL;
}
