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
			perror("execvp");
		}
	}
	else 
	{
		waitpid(pid, &status, 0);
	}
}
