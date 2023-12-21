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

Arguments *arguments_init(Arguments *self, InputBuffer *input)
{
        /* I intend to realloc memory if the initial malloc is not enough.*/
        size_t current_capacity = 64;
        /* I will traverse through the buffer with a pointer that NULL-terminates its internal tokens.
         * Those NULL-terminated tokens will be copied into and owned by the Arguments struct as strings.*/
        char *token;

        /* I don't want to dereference null pointers so I check for that here. */
        if (self == NULL || input == NULL)
                return (NULL);

        /* This is the first attempt at allocating enough memory for storing the arguments. */
        self->arguments = malloc(current_capacity * sizeof(char *));

        /* I need to know if memory allocation failed so I check for that here.*/
        if (self->arguments == NULL)
                return (NULL);

        /* Currently there are no arguments stored in the struct.*/
        self->count = 0;

        /* I need to recognise the tokens in the buffer so they can be added
         * to the Arguments struct. */
        token = strtok(input->buffer, " ");

        /* So long as there are tokens, I will add them to the struct. */
        while (token != NULL)
        {
                /* First, I need to make sure there is enough memory allocated. */
                if (self->count >= current_capacity)
                {
                        /* If there isn't, double the amount allocated */
                        current_capacity *= 2;
                        self->arguments = realloc(self->arguments, current_capacity * sizeof(char *));
                        /* Confirm that allocation was successful. */
                        if (self->arguments == NULL)
                                /*
                                 * Allocation was not successful.
                                 * Do I need to free any memory?
                                 */
                                return (NULL);

                }

                /* Add the NULL-terminated token to the struct and use strdup to ensure
                 * the struct has ownership of the string. This creates the argument.*/
                self->arguments[self->count] = strdup(token);
                /* The struct is storing one more argument now. Increase count.*/
                self->count++;
		/* Get the next internal token. */
		token = strtok(NULL, " ");
        }

        /* The arguments array must be NULL terminated. */
        self->arguments[self->count] = NULL;

        return (self);
}

