#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

#ifndef INPUTBUFFER_H
#define INPUTBUFFER_H
#include "inputbuffer.h"
#endif

#ifndef ARGUMENTS_H
#define ARGUMENTS_H
#include "arguments.h"
#endif

#define TRUE 1

/* Shell status codes - these are returned by the evaluate stage of the REPL */
#define EXIT_COMMAND 0
#define COMMAND_NOT_FOUND 127
#define ENV_COMMAND 10
#define EOF_ENCOUNTERED -1
#define EXECUTABLE_COMMAND 1
#define EMPTY_INPUT 3

extern char **environ;

void print_prompt(void);
void print_command_not_found_error(char *str);
void printenv_with_environ(void);
InputBuffer *new_input_buffer(void);
char *readline(FILE *stream, InputBuffer *input_buffer);
void close_input_buffer(InputBuffer *input_buffer);
int evaluate(char *str);
int execute(char **command);
void trim(char * const string);
void parse(char *command);
int is_executable(char *str);
void initialise_command_array(char *line, char *args[], int max_args);
void process_command(char *command, Arguments *args, InputBuffer *input_buffer, int *exit_code);

#endif /* SHELL_H */
