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
 * is_env - Checks if the input string is "env".
 *
 * @str: The input string to check.
 *
 * Return: 1 if the string is "env", 0 otherwise.
 */
int is_env(char *str)
{
	if (strcmp(str, "env") == 0)
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
 * is_not_found - Checks if the input string is executable.
 *
 * @str: The input string to check.
 *
 * Return: 1 if the string is not executable, 2 otherwise.
 */
int is_not_found(char *str)
{
	if (find_executable(str))
	{
		return (2);
	}
	return (1);
}
