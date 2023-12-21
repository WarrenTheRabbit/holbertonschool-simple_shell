#include "command.h"

Command *command_init(char *command_name, Arguments *args)
{
        /* Allocate memory for struct. */
        Command *command = malloc(sizeof(Command));
        /* If memory allocation failed, return NULL */
        if (command == NULL)
                return (NULL);

        command->args = args;
        command->command_name = strdup(command_name);

        cmd->execute = &execute_external;
