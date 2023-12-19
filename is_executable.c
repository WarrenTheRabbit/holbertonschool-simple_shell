#include "shell.h"

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
