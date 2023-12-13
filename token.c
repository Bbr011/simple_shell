#include "shell.h"

/*
 * tknzr - tokenizer function
 * @line: line to be tokenized
 * Return: NULL or cmd
 */

char **tknzr(char *line)
{
	char *t = NULL;
	char *tempo = NULL;
	int count = 0;
	int i = 0;
	char **cmd = NULL;

	if (!line)
		return (NULL);
	tempo = _strdup(line);
	t = strtok(tempo, " \t\n");
	if (t == NULL)
	{
		free(line), line = NULL;
		free(tempo), tempo = NULL;
		return (NULL);
	}
	while (t)
	{
		count++;
		t = strtok(NULL, " \t\n");
	}
	free(tempo), tempo = NULL;
	cmd = malloc(sizeof(char *) * (count + 1));
	if (!cmd)
	{
		free(line), line = NULL;
		return (NULL);
	}
	t = strtok(line, " \t\n");
	while (t)
	{
		cmd[i] = _strdup(t);
		t = strtok(NULL, " \t\n");
		i++;
	}
	free(line), line = NULL;
	cmd[i] = NULL;
	return (cmd);
}
