#include "shell.h"


int main(void)
{
	InputBuffer *input_buffer = new_input_buffer();

	while (TRUE)
	{
		print_prompt();
		readline(input_buffer);

		if (strcmp(input_buffer->buffer, "exit") == 0)
		{
			close_input_buffer(input_buffer);
			exit(EXIT_SUCCESS);
		}
		else
		{
			printf("hsh: %s :command not found\n", input_buffer->buffer);
		}
	}
}
