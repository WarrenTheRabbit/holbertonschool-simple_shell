#include "shell.h"

/**
 * is_exit - Checks if the input string is "exit".
 *
 * @str: The input string to check.
 *
 * Return: 1 if the string is "exit", 0 otherwise.
 */

int is_exit(char *str)
{
	if (strcmp(str, "exit") == 0)
	{
		return (1);
	}
	return (0);

}

/**
 * is_eof - Checks if the input string is NULL.
 *
 * @str: The input string to check.
 *
 * Return: 1 if the string is NULL, 0 otherwise.
 */
int is_eof(char *str)
{
	if (!str)
	{
		return (1);
	}
	return (0);
}

/**
 * is_empty - Checks if the input string is empty.
 *
 * @str: The input string to check.
 *
 * Return: 1 if the string is empty, 0 otherwise.
 */
int is_empty(char *str)
{
	if (strlen(str) == 0)
		return (1);
	return (0);
}

/**
 * evaluate - Evaluates the input string and determines the command type.
 *
 * @str: The input string to evaluate.
 *
 * Return: The command type based on the evaluation.
 */
int evaluate(char *str)
{
	if (is_eof(str)) /*Must guard against NULL first with this check */
		return (EOF_ENCOUNTERED);
	else if (is_empty(str))
		return (EMPTY_INPUT);
	else if (is_exit(str))
		return (EXIT_COMMAND);
	else if (is_eof(str))
		return (EOF_ENCOUNTERED);
	else if (is_executable(str))
		return (EXECUTABLE_COMMAND);
	return (COMMAND_NOT_FOUND);
}
