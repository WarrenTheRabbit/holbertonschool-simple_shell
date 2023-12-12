#include "shell.h"


int main(void)
{
	int status;
	char *input;
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
			print_command_not_found_error(command);
		}
	}
}
