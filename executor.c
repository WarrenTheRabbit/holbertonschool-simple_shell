#include "shell.h"

void execute(char **args)
{
	int status;
	pid_t pid;

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
	}
	else if (pid == 0)
	{
		/* Child process is executing. */
		if (execve(args[0], args, NULL) == -1)
		{
			/* print an error message */
			write(STDERR_FILENO, "Command not found: ", 19);
			write(STDERR_FILENO, args[0], strlen(args[0]));
			write(STDERR_FILENO, "\n", 1);

			/* exit to avoid continuing with incorrect execution */
			exit(EXIT_FAILURE);
		}
	}
	else 
	{
		waitpid(pid, &status, 0);
	}
}
