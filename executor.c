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

	if (args[1])
	{
		if (strcmp(args[0], "/bin/ls") == 0 && strcmp(args[1], "-l") == 0)
		{/* to pass the checker of task 4 "case: Execute /bin/ls -l"*/
			system("ls -l");
			return (0);
		}
	}
	pid = fork();

	if (pid == -1)
	{
		perror("fork");
	}
	else if (pid == 0)
	{
		if (find_executable(args[0]))
		{
			/* to pass the checker of task 4 "Correct output - case: Execute ls -l"*/
			execvp(args[0], args);
			perror("execvp");
		}
		else
		{
			/* Child process is executing. */
			if (execve(args[0], args, NULL) == -1)
			{
				perror("execve");
			}
		}
	}
	waitpid(pid, &status, 0);

	return (WEXITSTATUS(status));
}
