#include "shell.h"

void initialise_command_array(char *line, char *args[], int max_args)
{
	int arg_count = 0;
	char *token;
	int i;

	if (line == NULL)
		return;
	
	token = strtok(line, " ");

	while (token != NULL  && arg_count < max_args -1)
	{
		args[arg_count++] = token;
		token = strtok(NULL, " ");
	}
	
	for (i = 0; i < arg_count; i++)
	{
		if (args[i])
		{
			printf("args[%d] = %s\n", i, args[i]);
			trim(args[i]);
			printf("trim(args[%d]) = %s\n", i, args[i]);
		}
	}
	/* NULL terminate array for exec call. */
	args[arg_count] = NULL;
}
