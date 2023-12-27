#include "shell.h"

/**
 * file_exist_pwd - Checks if the input filename exist in PWD.
 *
 * @str: The input string to check.
 *
 * Return: 1 if the input filename exist, 0 otherwise.
 */

int file_exist_pwd(char *file)
{
	const char *filename = file;

	struct stat file_stat;
	int result = stat(filename, &file_stat);

	if (result == 0)
	{
		return (1); /* file exists in pwd*/
	}
	else
	{
		return (0);
	}
}
