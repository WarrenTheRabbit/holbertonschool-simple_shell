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

// int is_bin_command(char *str)
// {
	// char *delimiter = ":";
	// char *token;
	// const char *key = "PATH";
	// const char *command_path = "/bin";
	// char *PATH, cp_path[1024];
	// char **dir_list;
	// int counter;

	// counter = 0;
	// PATH = getenv(key);
	// strcpy(cp_path, PATH);
	// token = strtok(cp_path, delimiter);
	// dir_list = NULL;
	// while (token != NULL)
	// {
	// 	if (strcmp(token, command_path) == 0)
	// 	{
	// 		dir_list = get_dir(token);
	// 		if (dir_list == NULL)
	// 		{
	// 			return (0);
	// 		}
	// 		while (dir_list[counter])
	// 		{
	// 			if (strcmp(dir_list[counter], str) == 0)
	// 			{
	// 				free_grid(dir_list);
	// 				return (1);
	// 			}
	// 			counter = counter + 1;
	// 		}
	// 		free_grid(dir_list);
	// 		return (0);
	// 	}
	// 	token = strtok(NULL, delimiter);
	// }
	// free_grid(dir_list);
// 	return (0);
// }

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
	else if (is_env(str))
		return (ENV_COMMAND);
	else if (is_eof(str))
		return (EOF_ENCOUNTERED);
	else if (is_executable(str))
		return (EXECUTABLE_COMMAND);
	else if (has_bin_command(str))
		return (BIN_COMMAND);
	return (COMMAND_NOT_FOUND);
}
