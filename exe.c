#include "shell.h"

/*
 * _exe - executer function
 * @cmd: command
 * @argv: arguments
 * Return: sts
 */

int _exe(char **cmd, char **argv)
{
	int sts;
	pid_t child;

	child = fork();
	if (child == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
			perror(argv[0]);
			freestr(cmd);
			exit(0);
		}
	}
	else
	{
		waitpid(child, &sts, 0);
		freestr(cmd);
	}
	return (WEXITSTATUS(sts));
}
