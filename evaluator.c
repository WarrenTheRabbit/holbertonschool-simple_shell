#include "shell.h"
#include <ctype.h>

void trim_spaces(char *str)
{
	int start = 0, end = strlen(str) - 1;

	/* trim leading spaces */
	while (isspace(str[start]))
	{
		start++;
	}
	/* trim trailing spaces */
	while (end > start && isspace(str[end]))
	{
		end--;
	}
	/* move the null terminator to the end */
	str[end + 1] = '\0';
	/* move the trimmed string to the beginning */
	memmove(str, str + start, end - start + 2);
}

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
		/* trim spaces before checking executability */
		trim_spaces(str);
		/* check for spaces-only or empty string */
		if (strspn(str, " \t\n") == strlen(str) || isspace(str[0]) || isspace(str[strlen(str) - 1]))
		{
			write(1, "Empty command or command surrounded by spaces\n", 47);
			return (COMMAND_NOT_FOUND);
		}
		return (EXECUTABLE_COMMAND);
	}
	
	return (COMMAND_NOT_FOUND);
}




