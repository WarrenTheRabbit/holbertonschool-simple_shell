#include "shell.h"

void initialise_command_array(char *line, char *args[], int max_args)
{
	int arg_count = 0;
	char *token = strtok(line, " ");

	while (token != NULL  && arg_count < max_args -1)
	{
		args[arg_count++] = token;
		token = strtok(NULL, " ");
	}

	/* NULL terminate array for exec call. */
	args[arg_count] = NULL;
}
