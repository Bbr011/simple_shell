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

/*getenviron*/
char *_getenv(char *var);

/*getpath*/
char *_handlepath(char *cmd);

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
int _exe(char **cmd, char **argv, int indx);

/*fun*/
void freestr(char **ar);
void printerror(char *n, char *cmd, int index);
char *_ita(int n);
void strrev(char *str, int ln);

/*builtincheck*/
int builtincheck(char *cmd);
void exithsh(char **cmd, int *sts);
void prtenviron(char **cmd, int *sts);
void handlebuiltin(char **cmd, char **argv, int *sts, int index);
#endif
