#include "shell.h"


int main(void)
{
	int status;
	char *command;
	char *args[10];
	FILE *stream = stdin;
	InputBuffer *input_buffer = new_input_buffer();
	
	/* print environment variables before the main loop */
	printenv_with_environ();

	while (TRUE)
	{
		if (isatty(STDIN_FILENO))
		{
			print_prompt();
		}
		command = readline(stream, input_buffer);
		initialise_command_array(command, args, 10);

		/**
		 * debugging output: print the command before executing
		 */
		write(STDOUT_FILENO, "Command: ", 9);
		write(STDOUT_FILENO, args[0], strlen(args[0]));
		write(STDOUT_FILENO, "\n", 1);
		


		/**
		 * Commented out because segmentation fault resulted in non-interactive mode.
		 *
		 * parse(command); 
		 *
		 */
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
				break;

			case EOF_ENCOUNTERED:
				close_input_buffer(input_buffer);
				/* If a prompt was printed, print a newline. */
				if (isatty(STDIN_FILENO))
						write(STDOUT_FILENO, "\n", 1);
				exit(EXIT_SUCCESS);
				break;

			case EXECUTABLE_COMMAND:
				execute(args);	
				break;

			default:
				write(STDOUT_FILENO, "Unhandled case\n", 15);
				break;
		}
	}
	
	return (EXIT_FAILURE);
}
