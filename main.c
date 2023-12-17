#include "shell.h"


int main(void)
{
	int status;
	char *command;
	FILE *stream = stdin;
	InputBuffer *input_buffer = new_input_buffer();
	
	while (TRUE)
	{
		print_prompt();
		command = readline(stream, input_buffer);
		status = evaluate(command);
		
		switch (status)
		{
			case EXIT_COMMAND:
				close_input_buffer(input_buffer);
				exit(EXIT_SUCCESS);
				break;

			case COMMAND_NOT_FOUND:
				print_command_not_found_error(command);
				break;

			case ENV_COMMAND:
				printenv_with_environ();
				break;

			default:
				printf("unhandled case\n");
				break;
		}
	}
	
	return (EXIT_FAILURE);
}
