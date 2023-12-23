#include "shell.h"

char *_getenv(const char *var_name)
{
	char **env = environ;

	while (*env != NULL)
	{
		if (strncmp(*env, var_name, strlen(var_name)) == 0 && (*env)[strlen(var_name)] == '=')
		{
			return (*env + strlen(var_name) + 1);
		}
		env++;
	}

	return (NULL);
}
