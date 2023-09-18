#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

extern char **environ;

typedef struct mybuild
{
	char *name;
	void (*func)(char **);
} mybuild;

char *str_concat(char *s1, char *s2);
char *_strdup(char *str);
unsigned int _strlen(char *str);
char **split_path(char *path);
char *_get_path(const char *name);
char *path_checker(char *filename, char **arr);
void ext(char **arv);
void(*checkbuild(char **arv))(char **arv);

#endif 
