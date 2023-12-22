#include "shell.h"

/**
 * execute - Executes a command in a child process.
 *
 * @args: An array of strings representing the command and its arguments.
 *
 * Return: The exit status of the child process.
 */
int execute(char **args)
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
			perror("execve");
		}
	}
	waitpid(pid, &status, 0);

	return (WEXITSTATUS(status));
}
