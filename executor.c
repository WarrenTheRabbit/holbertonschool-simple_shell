#include "shell.h"

void execute(char *command)
{
	int status;
	char *args[2];
	pid_t pid;

	args[0] = command;
	args[1] = NULL;
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
			perror("execvp");
		}
	}
	else 
	{
		waitpid(pid, &status, 0);
	}
}
