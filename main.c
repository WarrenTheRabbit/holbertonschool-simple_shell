#include "shell.h"


int main(void)
{
	int status, exit_code;
	char *command;
	char *args[1024];
	FILE *stream = stdin;
	InputBuffer *input_buffer = new_input_buffer();

	while (TRUE)
	{
		if (isatty(STDIN_FILENO))
		{
			print_prompt();
		}
		command = readline(stream, input_buffer);
		trim(command);
		initialise_command_array(command, args, 1024);


		/**
		 * Commented out because segmentation fault resulted in non-interactive mode.
		 *
		 * parse(command); 
		 *
		 */
		status = evaluate(command);
		
		if (!exit_code)
			exit_code = 0;

		switch (status)
		{
			case EMPTY_INPUT:
				break;

			case EXIT_COMMAND:
				close_input_buffer(input_buffer);
				exit(exit_code);
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
				exit(exit_code);
				break;

			case EXECUTABLE_COMMAND:
				exit_code = execute(args);	
				break;

			default:
				printf("unhandled case\n");
				break;
		}
	}
	
	return (EXIT_FAILURE);
}
