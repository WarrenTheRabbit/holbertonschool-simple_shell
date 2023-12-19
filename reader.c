#include "shell.h"


/**
 * new_input_buffer - returns a small wrapper around the state needed by 
 * getline()
 *
 * Description:
 * This function prepares an object with the state needed by the 'getline'
 * call.
 *
 * getline(char **lineptr, size_t *n, FILE *stream) reads up to an including
 * the newline character. Unlike 'gets' and 'fgets', it does a read that is safe
 * and complete: it uses realloc to resize the lineptr buffer to ensure there
 * is enough room to store the complete line. It won't trunate the read or 
 * access invalid memory. If the buffer length is longer than the input, getline
 * will use the existing buffer space and null terminate the string, leaving the
 * buffer beyond it untouched.
 *
 * Return: an InputBuffer object
 */
InputBuffer *new_input_buffer(void)
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
char *readline(FILE *stream, InputBuffer *input_buffer)
{
	ssize_t bytes_read = getline(
					&(input_buffer->buffer), 
					&(input_buffer->buffer_length),
					stream
			);

	if (bytes_read == -1)
	{
		return (NULL);
	}
	/* Discard the trailing newline by replacing it with null character. */
	input_buffer->input_length = bytes_read - 1;
	input_buffer->buffer[bytes_read - 1] = 0;

	return (input_buffer->buffer);
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
