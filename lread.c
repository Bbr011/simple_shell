#include "shell.h"

/*
 * lread - line reader function
 * Return: line
 */

char *lread(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t num;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	num = getline(&line, &len, stdin);/*getline function*/
	if (num == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
