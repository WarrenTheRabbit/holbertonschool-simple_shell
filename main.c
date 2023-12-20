#include "shell.h"

/**
 * process_command - Process the given command and update the status and
 * exit code.
 * @command: The command to process.
 * @args: The array of arguments for the command.
 * @input_buffer: Pointer to the InputBuffer.
 * @exit_code: starts as 0 but can be modified on failure.
 * Return: The status of the command processing.
 */
void process_command(
		char *command,
		char *args[],
		InputBuffer *input_buffer,
		int *exit_code)
{
	int status = evaluate(command);

	switch (status)
	{
		case EMPTY_INPUT:
			break;
		case EXIT_COMMAND:
			close_input_buffer(input_buffer);
			exit(*exit_code);
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
			exit(*exit_code);
			break;
		case EXECUTABLE_COMMAND:
			*exit_code = execute(args);
			break;
		default:
			printf("unhandled case\n");
			break;
	}
}

/**
 * main - The main function for the shell program.
 * Return: EXIT_FAILURE if the program encounters an error, otherwise, it
 * does not return.
 */
int main(void)
{
	char *command;
	int exit_code = 0;
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
		process_command(command, args, input_buffer, &exit_code);
	}
	return (exit_code);
}
