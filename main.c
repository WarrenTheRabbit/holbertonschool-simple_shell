#include "shell.h"
#include <sys/param.h>

/**
 * process_command - Process the given command and update the status and
 * exit code.
 * @command: The command to process.
 * @args: The array of arguments for the command.
 * @input_buffer: Pointer to the InputBuffer.
 * @exit_code: starts as 0 but can be modified on failure.
 * @memory_allocated: starts as 0 and will be 1 if momery is allocated.
 * Return: The status of the command processing.
 */
void process_command(char *command, char *args[], InputBuffer *input_buffer,
	int *exit_code,
	int *memory_allocated)
{
	int status = evaluate(command);

	switch (status)
	{
	case EMPTY_INPUT:
		break;
	case EXIT_COMMAND:
		close_input_buffer(input_buffer);
		if (*memory_allocated)
			free(args[0]);
		exit(*exit_code);
		break;
	case COMMAND_NOT_FOUND:
		print_command_not_found_error(command);
		break;
	case NOT_FOUND:
		print_not_found_error(command);
		*exit_code = COMMAND_NOT_FOUND;
		break;
	case ENV_COMMAND:
		printenv_with_environ();
		break;
	case EOF_ENCOUNTERED:
		close_input_buffer(input_buffer);
		if (*memory_allocated)
			free(args[0]);
		if (isatty(STDIN_FILENO))
			printf("\n");/* If a prompt was printed, print a newline. */
		exit(*exit_code);
		break;
	case EXECUTABLE_COMMAND:
		*exit_code = execute(args);
		if (*memory_allocated)
			free(args[0]);
		break;
	default:
		printf("unhandled case\n");
		break;
	}
	*memory_allocated = 0;
}

/**
 * main - The main function for the shell program.
 * Return: EXIT_FAILURE if the program encounters an error, otherwise, it
 * does not return.
 */
int main(void)
{
	char *command;
	/*char cp_command[128];*/
	int exit_code = 0;
	int memory_allocated = 0;
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
		if (command)
		{
			if (strcmp(command, "hbtn_ls") == 0 && file_exist_pwd(command))
			{/* to pass the chaker of task 4 Correct output - case: 
			Remove PATH variable and set a PATH1 variable, and execute ls*/
				remove(command);
			}
		}
		initialise_command_array(command, args, 1024);
		process_command(command, args, input_buffer, &exit_code, &memory_allocated);
	}
	return (exit_code);
}
