#include <stdlib.h>

/**
 * struct InputBuffer - a wrapper around the state needed for getline()
 * and its return value
 * Description:
 * getline(char **lineptr, size_t *n, FILE *stream) has three state
 * requirements: - reads an entire line
 * from `stream` and stores the address of the buffer containing the text
 * into *lineptr.
 * If *lineptr is set to NULL before the call, then getline() will allocate
 * a buffer for storing the line.
 * @buffer: a string buffer
 * @buffer_length: variable
 * @input_length: to store the number of bytes read by getline()
 */
typedef struct
{
        char *buffer;
        size_t buffer_length;
        ssize_t input_length;
} InputBuffer;


Something I am unsure I want.
