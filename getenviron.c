#include "shell.h"

/*
 * _getenv - finds an environment variable
 * @var: the variable
 * Return: value or NULL
 */

char *_getenv(char *var)
{
	int a;
	char *tempo;
	char *m, *value;
	char *valueb;

	for (a = 0; environ[a]; a++)
	{
		tempo = _strdup(environ[a]);
		m = strtok(tempo, "=");
		if (_strcmp(m , var) == 0)
		{
			value = strtok(NULL, "\n");
			valueb = _strdup(value);
			free(tempo);
			return (valueb);
		}
		free(tempo), tempo = NULL;
	}
	return (NULL);
}
