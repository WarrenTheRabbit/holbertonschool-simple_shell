#include "shell.h"

int is_exit(char *str)
{
	if (strcmp(str, "exit") == 0)
	{
		return (1);
	}
	return (0);

}


int evaluate(char *str)
{
	if (is_exit(str))
	{
		return (EXIT_COMMAND);
	}
	return (1);

}




