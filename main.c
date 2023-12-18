#include "shell.h"

int main(void)
{
	int status;
	char *command;
	char *args[10];
	FILE *stream = stdin;
	InputBuffer *input_buffer = new_input_buffer();

	while (TRUE)
	{
		if (isatty(STDIN_FILENO))
		{
			print_prompt();
		}
		command = readline(stream, input_buffer);
		if (!command)
		{
			return (EXIT_FAILURE);
		}
		parse(command);
		initialise_command_array(command, args, 10);

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
				exit(2);
				break;

			case COMMAND_NOT_FOUND:
				print_command_not_found_error(command);
				break;

			case ENV_COMMAND:
				printenv_with_environ();
				break;

			case SPACE_ONLY:
				if (!isatty(STDIN_FILENO))
					exit(EXIT_SUCCESS);
				break;
			case EOF_ENCOUNTERED:
				close_input_buffer(input_buffer);
				/* If a prompt was printed, print a newline. */
				if (isatty(STDIN_FILENO))
					printf("\n");
				exit(2);
				break;

			case EXECUTABLE_COMMAND:
				execute(args);
				break;

			default:
				printf("unhandled case\n");
				break;
		}
	}

	return (EXIT_FAILURE);
}
