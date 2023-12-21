#include "shell.h"
#include <dirent.h>

/**
 * has_bin_command - Check if a command exists in the /bin directory
 * @str: The command to check
 *
 * Description:
 * This function checks if the specified command exists in the /bin directory.
 * Return: 1 if the command is found, 0 otherwise.
 */
int has_bin_command(char *str)
{
	char *delimiter = ":";
	char *token;
	const char *key = "PATH";
	const char *command_path = "/bin";
	char *PATH, cp_path[1024];
	struct dirent *entry;
	DIR *dir_pointer;
	
	PATH = getenv(key);
	strcpy(cp_path, PATH);
	token = strtok(cp_path, delimiter);
	dir_pointer = opendir(command_path);
	
	while (token != NULL)
	{
		if (strcmp(token, command_path) == 0)
		{
			while ((entry = readdir(dir_pointer)) != NULL)
			{
				if (strcmp(entry->d_name, str))
				{
					closedir(dir_pointer);
					return (1);
				}
			}
		}
		token = strtok(NULL, delimiter);
	}
	closedir(dir_pointer);
	return (0);
}
