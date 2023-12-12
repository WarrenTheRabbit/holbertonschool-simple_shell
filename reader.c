#include "shell.h"


/**
 * new_input_buffer - returns a small wrapper around the state needed by getline()
 *
 * Description:
 * 	This function prepares an object with the state needed by the 'getline'
 * 	call.
 *
 * 	getline(char **lineptr, size_t *n, FILE *stream) reads up to an including
 * 	the newline character. Unlike 'gets' and 'fgets', it does a read that is safe
 * 	and complete: it uses realloc to resize the lineptr buffer to ensure there
 * 	is enought room to store the complete line. It won't trunate the read or 
 * 	access invalid memory.
 *
 * Return: an InputBuffer object
 */
InputBuffer *new_input_buffer()
{
	InputBuffer *input_buffer = malloc(sizeof(InputBuffer));
	input_buffer->buffer = NULL;
	input_buffer->buffer_length = 0;
	input_buffer->input_length = 0;

	return (input_buffer);
}


/**
 * readline - reads a line of input into a buffer and excludes the newline character
 * @input_buffer - a wrapper for the state needed by getline()
 * Return: nothing
 */
void readline(InputBuffer *input_buffer)
{
	ssize_t bytes_read = getline(
					&(input_buffer->buffer), 
					&(input_buffer->buffer_length),
					stdin
			);

	/* Discard the trailing newline */
	input_buffer->input_length = bytes_read - 1;
	input_buffer->buffer[bytes_read - 1] = 0;
}

/**
 * close_input_buffer - frees the memory allocated by new_input_buffer()
 * 	and readline()
 * @input_buffer: a struct that stores the state needed by getline()
 * Return: nothing
 */
void close_input_buffer(InputBuffer *input_buffer)
{
	free(input_buffer->buffer);
	free(input_buffer);
}
