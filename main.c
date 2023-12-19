#include "shell.h"

/**
 * handle_exit - Handles the exit command, frees resources, and exits
 * the program.
 * @input_buffer: The input buffer structure.
 * @status: The exit status.
 */
void handle_exit(InputBuffer *input_buffer, int status)
{
	close_input_buffer(input_buffer);
	exit(status);
}

/**
 * handle_executable_command - Handles the execution of an executable command.
 * @args: The array of command arguments.
 * @status: The exit status.
 * @status_is_set: Flag indicating if the exit status is set.
 */
void handle_executable_command(char *args[], int *status, int *status_is_set)
{
	*status = execute(args);
	*status_is_set = 1;
}

/**
 * main - The main function for the shell program.
 * Return: EXIT_FAILURE if the program encounters an error, otherwise, it
 * does not return.
 */
int main(void)
{
	int status;
	int status_is_set = 0;
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

		if (!status_is_set)
			status = 0;

		switch (status)
		{
			case EMPTY_INPUT: break;

			case EXIT_COMMAND: handle_exit(input_buffer, status); break;

			case COMMAND_NOT_FOUND: print_command_not_found_error(command); break;

			case ENV_COMMAND: printenv_with_environ(); break;

			case EOF_ENCOUNTERED:
				close_input_buffer(input_buffer);
				/* If a prompt was printed, print a newline. */
				if (isatty(STDIN_FILENO))
					printf("\n");
				handle_exit(input_buffer, status);
				break;

			case EXECUTABLE_COMMAND:
				handle_executable_command(args, &status, &status_is_set);
				break;

			default: printf("unhandled case\n"); break;
		}
	}
	return (EXIT_FAILURE);
}
