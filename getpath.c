#include "shell.h"

char *_handlepath(char *cmd)
{
	struct stat yh;
	char *fcmd, *pthe;
	char *dir;
	int a;

	for (a = 0; cmd[a]; a++)
	{
		if (cmd[a] == '/')
		{
			if (stat(cmd, &yh) == 0)
				return (_strdup(cmd));
			return (NULL);
		}
	}

	pthe = _getenv("PATH");
	if (!pthe)
		return (NULL);

	dir = strtok(pthe, ":");
	while (dir)
	{
		fcmd = malloc(_strlen(cmd) + _strlen(dir) + 2);
		if(fcmd)
		{
			_strcpy(fcmd, dir);
			_strcat(fcmd, "/");
			_strcat(fcmd, cmd);
			if (stat(fcmd, &yh) == 0)
			{
				free(pthe);
				return(fcmd);
			}
			free(fcmd), fcmd = NULL;
			dir = strtok(NULL, ":");
		}
	}
	free(pthe);
	return(NULL);
}
