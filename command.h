#ifndef ARGUMENTS_H
#define ARGUMENTS_H
#include "arguments.h"
#endif

#include <stdlib.h>
#include <stddef.h>

typedef struct Command
{
	char *command_name
	Arguments *args;
	int (*execute)(struct Command *self);
} Command;


Command *command_init(char *command_name, Arguments *args);
