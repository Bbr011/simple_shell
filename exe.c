#include "shell.h"

/*
 * _exe - executer function
 * @cmd: command
 * @argv: arguments
 * Return: sts
 */

int _exe(char **cmd, char **argv, int indx)
{
	int sts;
	pid_t child;
	char *fcmd;

	fcmd = _handlepath(cmd[0]);
	if (!fcmd)
	{
		printerror(argv[0], cmd[0], indx);
		freestr(cmd);
		return (127);
	}
	child = fork();
	if (child == 0)
	{
		if (execve(fcmd, cmd, environ) == -1)
		{
			free(fcmd), fcmd = NULL;
			freestr(cmd);
		}
	}
	else
	{
		waitpid(child, &sts, 0);
		freestr(cmd);
		free(fcmd), fcmd = NULL;
	}
	return (WEXITSTATUS(sts));
}
