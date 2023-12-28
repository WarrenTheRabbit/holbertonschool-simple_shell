#include "shell.h"

/**
 * evaluate - Evaluates the input string and determines the command type.
 *
 * @str: The input string to evaluate.
 *
 * Return: The command type based on the evaluation.
 */
int evaluate(char *str)
{
	int i;

	if (str)
	{
		i = is_not_found(str);
	}
	if (is_eof(str))/*Must guard against NULL first with this check */
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
	else if (i == 1)
		return (NOT_FOUND);
	else if (i == 2)
		return (EXECUTABLE_COMMAND);
	return (COMMAND_NOT_FOUND);
}
