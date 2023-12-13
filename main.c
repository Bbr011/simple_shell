#include "shell.h"

/*
 * main - simple shell function
 * @ac: arguments count
 * @argv: arguments vector
 * Return: always 0
 */

int main(int ac, char **argv)
{
	int sts = 0;
	char *line = NULL;
	char **cmd = NULL;
	(void) ac;

	while (1)
	{
		line = lread();/*line reader function*/
		if (line == NULL)/*eof*/
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (sts);
		}
		cmd = tknzr(line);/*tokenizer function*/
		if (!cmd)
			continue;
		sts = _exe(cmd, argv);/*executer function*/
	}
}
