#include "shell.h"

/*
 * freestr - function that frees an srrsy of a string
 * @ar: array
 * Return: NULL
 */

void freestr(char **ar)
{
	int i;

	if (!ar)
		return;
	for (i = 0; ar[i]; i++)
	{
		free(ar[i]);
		ar[i] = NULL;
	}
	free(ar), ar = NULL;
}

char *_ita(int n)
{
	int a = 0;
	char buffer[20];

	if (n == 0)
		buffer[a++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[a++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buffer[a] = '\0';
	strrev(buffer, a);
	return (_strdup(buffer));
}
void strrev(char *str, int ln)
{
	int start = 0;
	int end = ln - 1;
	char tempo;

	while (start < end)
	{
		tempo = str[start];
		str[start] = str[end];
		str[end] = tempo;
		start++;
		end--;
	}
}
void printerror(char *n, char *cmd, int index)
{
	char *indx;
	char msg[] = ": not found\n";

	indx = _ita(index);
	write(STDERR_FILENO, n, _strlen(n));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, indx, _strlen(indx));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, msg, _strlen(msg));
	free(indx);
}

