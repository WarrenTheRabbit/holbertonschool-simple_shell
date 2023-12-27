#include "shell.h"

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
