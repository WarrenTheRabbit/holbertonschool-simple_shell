#include "shell.h"
#include <ctype.h>

int compare(const void *a, const void *b) {
    const char *file_a = *(const char **)a;
    const char *file_b = *(const char **)b;

    // Find the start of the filename by finding the last space in the string
    const char *filename_a = strrchr(file_a, ' ');
    const char *filename_b = strrchr(file_b, ' ');

    if (filename_a == NULL || filename_b == NULL) {
        fprintf(stderr, "Error parsing filenames.\n");
        exit(EXIT_FAILURE);
    }

    // Skip the space to start comparing the filenames
    filename_a++;
    filename_b++;

    return strcasecmp(filename_a, filename_b);
}


int small_to_capital(void)
{
    FILE *ls_output = popen("ls -l", "r");

    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int i;

    char **lines = NULL;
    int line_count = 0;

    if (ls_output == NULL)
    {
        fprintf(stderr, "Error opening pipe.\n");
        return EXIT_FAILURE;
    }

    while ((read = getline(&line, &len, ls_output)) != -1)
    {
        lines = realloc(lines, (line_count + 1) * sizeof(char *));
        lines[line_count] = strdup(line);
        line_count++;
    }

    qsort(lines, line_count, sizeof(char *), compare); // Sort lines case-insensitively

    for (i = 0; i < line_count; i++)
    {
        printf("%s", lines[i]); // Print sorted output
        free(lines[i]);         // Free memory allocated by strdup
    }

    free(lines);
    free(line);
    pclose(ls_output);

    return EXIT_SUCCESS;
}
