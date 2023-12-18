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
			perror("execve");
			/* use _exit to avoid atexit handlers */
			_exit(EXIT_FAILURE);
		}
	}
	else 
	{
		waitpid(pid, &status, 0);
	}
}
