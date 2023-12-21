#include "shell.h"
#include <dirent.h>

/**
 * free_grid - calls free_grid
 * @grid:  nested char
 *
 * Return: void
 */

void free_grid(char **grid)
{
    int counter;

    counter = 0;

    while (grid[counter])
    {
        free(grid[counter]);
        counter = counter + 1;
    }
    free(grid);
}

char **get_dir(char *path)
{
    struct dirent *entry;
    DIR *dir_pointer;
    int counter;
    char **dir_list;
    if (!path)
    {
        printf("Error path");
        exit(0);
    }
    counter = 0;
    dir_list = malloc(1024);
    if (dir_list == NULL)
    {
        exit(0);
    }
    dir_pointer = opendir(path);

    if (dir_pointer == NULL)
    {
        free(dir_list);
        perror("Error opening directory");
        exit(0);
    }

    while ((entry = readdir(dir_pointer)) != NULL)
    {
        dir_list[counter] = malloc(strlen(entry->d_name) + 1);
        if (dir_list[counter] == NULL)
        {
            perror("Error allocating memory");
            while (counter > 0)
            {
                free(dir_list[counter - 1]);
                counter--;
            }
            free(dir_list);
            closedir(dir_pointer);
            exit(EXIT_FAILURE);
        }
        if (entry->d_name[0] != '.')
        {
            strcpy(dir_list[counter], entry->d_name);
        }
        counter++;
    }
    dir_list[counter] = NULL;
    closedir(dir_pointer);
    return (dir_list);
}
