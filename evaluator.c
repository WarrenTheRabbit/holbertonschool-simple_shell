#include "shell.h"

int is_exit(char *str)
{
	if (strcmp(str, "exit") == 0)
	{
		return (1);
	}
	return (0);

}

int is_env(char *str)
{
	if (strcmp(str, "env") == 0)
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
	else if (is_env(str))
	{
		return (ENV_COMMAND);
	}
	return (COMMAND_NOT_FOUND);

}




