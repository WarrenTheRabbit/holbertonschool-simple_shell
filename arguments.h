#ifndef INPUTBUFFER_H
#define INPUTBUFFER_H
#include "inputbuffer.h"
#endif

typedef struct 
{
	char **arguments;
	size_t count;
} Arguments;

int arguments_init(Arguments *self, InputBuffer *input);
