#ifndef ARGUMENTS_H
#define ARGUMENTS_H
#include "arguments.h"
#endif

#ifndef INPUTBUFFER_H
#define INPUTBUFFER_H
#include "inputbuffer.h"
#endif

#include <string.h>
#include <stddef.h>
#include <stdlib.h>

int arguments_init(Arguments *self, InputBuffer *input)
{
        size_t current_capacity = 64;
        char *token;

        if (self == NULL || input == NULL)
                return (-1);

        self->arguments = malloc(current_capacity * sizeof(char *));

        if (self->arguments == NULL)
                return (-1);

        self->count = 0;

        token = strtok(input->buffer, " ");

        while (token != NULL)
        {
                if (self->count >= current_capacity)
                {
                        current_capacity *= 2;
                        self->arguments= realloc(self->arguments, current_capacity * sizeof(char *));
                        if (self->arguments == NULL)
                                return (-1);

                }

                self->arguments[self->count] = strdup(token);
                self->count++;
		token = strtok(NULL, " ");
        }

        self->arguments[self->count] = NULL;

        return (0);
}

