#include "shell.h"


int main(void)
{
	int status;
	char *command;
	FILE *stream = stdin;
	InputBuffer *input_buffer = new_input_buffer();
	
	while (TRUE)
	{
		if (isatty(STDIN_FILENO))
		{
			print_prompt();
		}
		command = readline(stream, input_buffer);
		parse(command);
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

			case EOF_ENCOUNTERED:
				close_input_buffer(input_buffer);
				/* If a prompt was printed, print a newline. */
				if (isatty(STDIN_FILENO))
						printf("\n");
				exit(EXIT_SUCCESS);
				break;

			case EXECUTABLE_COMMAND:
				execute(command);	
				break;

			default:
				printf("unhandled case\n");
				break;
		}
	}
	
	return (EXIT_FAILURE);
}
