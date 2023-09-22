#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>

#define PROMPT_MSG "$ "

#define UNUSED __attribute__((unused))
#define BUFFER_SIZE 1024
#define HELP_SETENV_MSG "setenv command:\n"
#define HELP_ENV_MSG "env command:\n"
#define HELP_CD_MSG "cd command:\n"
#define HELP_EXIT_MSG "exit command:\n"
#define HELP_UNSETENV_MSG "unsetenv command:\n"
#define HELP_MSG "help command:\n"

/**
 * struct about_info - Structure for a simple shell's program information
 * 
 * @alias_list: Array of strings for alias definitions
 * 
 * @tokens: Array of strings for command tokens
 * 
 * @cmd_name: String for the command name
 * 
 * @name_projects: String for project name
 * 
 * @file_desc: Integer for file descriptor
 * 
 * @get_line: String for input line
 * 
 * @env: Array of strings for environment variables
 */

typedef struct allInfo
{
	char **alias_list;
	char *get_line;
	char **tokens;
	char *name_projects;
	int execute_counter;
	int file_desc;
	char *cmd_name;
	char **env;
} allInfo;

/**
 * struct env_structure - Associates built-in command names with
 *                        their corresponding function pointers.
 * @built_in: Command names.
 * @function: Corresponding function pointers for execution.
 */

typedef struct env_structure
{
	char *built_in;
	int (*function)(allInfo *data);
} env_structure;
int exit_env(allInfo *data);
int commandBuilt(allInfo *data);
int stringSize(char *str);
char *string_repetitions(char *str);
int stringComparitions(char *str_one, char *str_two, int num);
int set_dir(allInfo *data, char *newDir);
int helpBuilt(allInfo *data);
int builtList(allInfo *data);
char **filePath(allInfo *data);
int searchFile(allInfo *data);
void free_array_pointes(char **array);
void freeData(allInfo *data);
int builtin_alias(allInfo *data);
int terPrint(char *str);
int check(char *file_path);
int env_builders(allInfo *data);
void tokenizeData(allInfo *data);
char *str_tok(char *line, char *delim);
int executed(allInfo *data);
void handleShortCut(int operations UNUSED);
int _getline(allInfo *data);
int logical_operations(char *commandArr[], int num, char operationArray[]);
int builder_set_key(allInfo *data);
int keyUnset(allInfo *data);
void stringLong(long number, char *str, int base);
int _atoi(char *strs);
int charSize(char *str, char *character);
void start_with(allInfo *data, int argc, char *argv[], char **env);
void size_of_(char *prompt, allInfo *data);
int new_buffer(char *buffer, char *concatStr);
void expandVar(allInfo *data);
void expand_alias(allInfo *data);
int errPrint(char *str);
int handle_error(int error_code, allInfo *data);
char *getKey(char *key, allInfo *data);
int setKey(char *key, char *value, allInfo *data);
int remove_key(char *key, allInfo *data);
void envPrint(allInfo *data);
char *mergeString(char *str_one, char *str_two);
void reverse(char *str);
void freeAll(allInfo *data);
int printfFun(allInfo *data, char *Name);
char *getFun(allInfo *data, char *Name);
int set_fun(char *alias_string, allInfo *data);

#endif /* MAIN_H */
