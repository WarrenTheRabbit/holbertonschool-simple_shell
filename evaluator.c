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

int evaluate(char *str)
{
	if (is_eof(str)) /*Must guard against NULL first with this check */
		return (EOF_ENCOUNTERED);
	else if (is_exit(str))
		return (EXIT_COMMAND);
	else if (is_env(str))
		return (ENV_COMMAND);
	else if (is_eof(str))
		return (EOF_ENCOUNTERED);
	else if (is_executable(str))
	{
		/* check for spaces-only or empty string */
		if (strspn(str, " \t\n") == strlen(str))
		{
			write(1, "Empty command\n", 14);
			return (COMMAND_NOT_FOUND);
		}
		return (EXECUTABLE_COMMAND);
	}
	
	return (COMMAND_NOT_FOUND);
}




