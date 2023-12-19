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


int is_eof(char *str)
{
	if (!str)
	{
		return (1);
	}
	return (0);
}

int is_empty(char *str)
{
	if (strlen(str) == 0)
		return (1);
	return (0);
}


int evaluate(char *str)
{
	if (is_eof(str)) /*Must guard against NULL first with this check */
		return (EOF_ENCOUNTERED);
	else if (is_empty(str))
		return (EMPTY_INPUT);
	else if (is_exit(str))
		return (EXIT_COMMAND);
	else if (is_env(str))
		return (ENV_COMMAND);
	else if (is_eof(str))
		return (EOF_ENCOUNTERED);
	else if (is_executable(str))
		return (EXECUTABLE_COMMAND);
	return (COMMAND_NOT_FOUND);
}




