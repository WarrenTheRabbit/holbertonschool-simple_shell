#include "shell.h"


int main(void)
{
	int status;
	char *command;
	InputBuffer *input_buffer = new_input_buffer();
	
	while (TRUE)
	{
		print_prompt();
		command = readline(input_buffer);
		status = evaluate(command);
		
		if (status == EXIT_COMMAND)
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
