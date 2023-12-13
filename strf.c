#include "shell.h"

/* strcmp - compaire two strings
 * @s1: first string
 * @s2: second string
 * Return: c
 */

int _strcmp(char *s1, char *s2)
{
	int c;

	c = (int)*s1 - (int)*s2;
	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
		c = (int)*s1 - (int)*s2;
	}
	return (c);
}

/* strlen - calculate the length of a string
 * @s: string 
 * Return: length
 */

int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}

/* strcmp - duplicate a string
 * @str: string
 * Return: p
 */

char *_strdup(const char *str)
{
	char *p;
	int i, len = 0;

	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		len++;
		str++;
	}
	str = str - len;
	p = malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
		p[i] = str[i];
	return (p);
}

/* strcat - concatenates two strings
 * @dest: first string
 * @src: second string
 * Return: dest
 */

char *_strcat(char *dest, char *src)
{
	char *p = dest;

	while (*p)
		p++;
	while (*src)
	{
		*p = *src;
		p++;
		src++;
	}
	*p = *src;
	return (dest);
}

/* strcmp - copies a string
 * @s1: first string
 * @s2: second string
 * Return: dest
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}
