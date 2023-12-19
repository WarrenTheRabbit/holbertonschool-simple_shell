#include "shell.h"

/**
 * is_executable - Checks if a file is executable.
 *
 * @str: The path to the file.
 *
 * Return: 1 if the file is executable, 0 otherwise.
 */

int is_executable(char *str)
{
	struct stat file_stat;

	if (stat(str, &file_stat) < 0)
		return (0);
	if (!S_ISREG(file_stat.st_mode))
		return (0);
	if (file_stat.st_mode & S_IXUSR)
		return (1);

	return (0);
}
