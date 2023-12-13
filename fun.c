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
