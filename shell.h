#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;

/*lread*/
char *lread(void);

/*strf*/
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strdup(const char *str);

/*token*/
char **tknzr(char *line);

/*exe*/
int _exe(char **cmd, char **argv);

/*fun*/
void freestr(char **ar);

#endif
