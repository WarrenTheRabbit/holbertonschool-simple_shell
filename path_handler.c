#include "shell.h"

/* return fill path*/

char *find_executable(const char *command)
{
	char *PATH;
	char *fullPath;
	char *cp_path;
	char *token;
	char *first_string;

	first_string = strdup(command);
	get_first_string(first_string, ' ');
	PATH = getenv("PATH");
	if (!PATH)
	{
		free(first_string);
		return (NULL);
	}
	fullPath = malloc(1024); /* need to free */
	if (!fullPath) {
        free(first_string);
        return NULL;
    }
	cp_path = strdup(PATH);
	token = strtok(cp_path, ":");
	while (token != NULL)
	{
		snprintf(fullPath, 1024, "%s/%s", token, first_string);
		if (access(fullPath, X_OK) == 0)
		{
			free(cp_path);
			free(first_string);
			return (fullPath);
		}
		token = strtok(NULL, ":");
	}
	free(cp_path);
	free(first_string);
	free(fullPath);
	return (NULL); /* Return NULL if executable not found */
}
