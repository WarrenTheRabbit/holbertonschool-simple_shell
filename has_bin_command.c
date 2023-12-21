#include "shell.h"
#include <dirent.h>

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
                    return (1);
                }
            }
        }
        token = strtok(NULL, delimiter);
    }
    return (0);
}
