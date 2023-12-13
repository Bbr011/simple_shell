#include "shell.h"

int builtincheck(char *cmd)
{
	int a;
	char *bltin[] = {"exit", "env", "setenv", "cd", NULL};

	for (a = 0; a < 4; a++)
	{
		if (_strcmp(cmd, bltin[a]) == 0)
			return (1);
	}
	return (0);
}

void exithsh(char **cmd, int *sts)
{
	freestr(cmd);
	exit(*sts);
}

void prtenviron(char **cmd, int *sts)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO,"\n", 1);
	}
	freestr(cmd);
	(*sts = 0);
}

void handlebuiltin(char **cmd, char **argv, int *sts, int index)
{
	(void) argv;
	(void) index;

	if (_strcmp(cmd[0], "exit") == 0)
		exithsh(cmd, sts);
	else if (_strcmp(cmd[0], "env") == 0)
		prtenviron(cmd, sts);
}
