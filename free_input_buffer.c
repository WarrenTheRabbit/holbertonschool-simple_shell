#include "shell.h"

void free_input_buffer(InputBuffer *input_buffer)
{
	if (input_buffer != NULL)
	{
		free(input_buffer->buffer);
		free(input_buffer);
	}
}
