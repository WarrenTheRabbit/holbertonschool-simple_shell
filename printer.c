#include "shell.h"

void print_prompt(void) 
{
	printf("$ ");
}

void print_command_not_found_error(char *str)
{
	printf("hash: %s :command not found\n", str);
}

void printenv_with_environ(void)
{
    extern char **environ;
    char ** cp_environ;

    cp_environ = environ;

    while (*cp_environ != NULL)
    {
        printf("%s\n", *cp_environ);
        cp_environ++;
    }
}
