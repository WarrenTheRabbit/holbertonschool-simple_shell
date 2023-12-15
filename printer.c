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

    while (*environ != NULL)
    {
        printf("%s\n", *environ);
        environ++;
    }
}
