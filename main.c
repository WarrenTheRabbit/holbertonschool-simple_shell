#include "shell.h"

/**
 * main - The main function for the shell program.
 * Return: EXIT_FAILURE if the program encounters an error, otherwise, it
 * does not return.
 */
int main(void)
{
	int status, exit_code;
	int exit_code_is_set = 0;
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
		
		status = evaluate(command);

		if (!exit_code_is_set)
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
				exit_code_is_set = 1;
				break;

			default:
				printf("unhandled case\n");
				break;
		}
	}
	return (EXIT_FAILURE);
}
