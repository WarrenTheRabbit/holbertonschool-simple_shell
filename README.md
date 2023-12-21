# holbertonschool-simple_shell
Simple Shell is a minimalistic UNIX command line interpreter developed as part of the Holberton School curriculum. The shell allows users to execute commands in both interactive and non-interactive modes.

## Table of Contents

- [Description](#description)
- [Flowchart](#flowchart)
- [File Structure](#file_structure)
- [System and Library calls](#system_and_library_calls)
- [Example of Use](#example_of_use)
- [Installation](#installation)
- [Authors](#authors)
- [Bugs](#bugs)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgements](#acknowledgements)

## Description

The Simple Shell project aims to create a basic command-line interpreter that mimics some of the functionalities of the standard Unix shell (/bin/sh). It is designed to handle simple commands, execute executables, and provide a basic environment for command execution.

## Flowchart

## File Structure

This table give a brief description of the files used for the simple shell to work, click on the names to get the source code.

| File | Content | Description |
| --- | --- | --- |
| [`shell.h`](https://github.com/WarrenTheRabbit/holbertonschool-simple_shell/blob/main/shell.h) | Header of the project | Contains the structures, prototypes, macros and external variables of the project. |
| [`main.c`](https://github.com/WarrenTheRabbit/holbertonschool-simple_shell/blob/main/main.c) | void process_command(); <br>int main(); | Mainloop, receive input from the Command Line Interface parse and execute it. |
| [`evaluator.c`](https://github.com/WarrenTheRabbit/holbertonschool-simple_shell/blob/main/evaluator.c) | int is_exit(); <br>int is_env(); <br>int is_eof(); <br>int is_empty(); <br>int evaluate(); | Check if the input string is "exit"/ "env"/ NULL/ empty. <br>Evaluates the input string and determines the command type. |
| [`is_executable.c`](https://github.com/WarrenTheRabbit/holbertonschool-simple_shell/blob/main/is_executable.c) | int is_executable(); | Check if a file is executable. |
| [`executor.c`](https://github.com/WarrenTheRabbit/holbertonschool-simple_shell/blob/main/executor.c) | int execute(); | Execute a command in a child process. |
| [`parser.c`](https://github.com/WarrenTheRabbit/holbertonschool-simple_shell/blob/main/parser.c) | void parse(); | Trim whitespace from the given command. |
| [`printer.c`](https://github.com/WarrenTheRabbit/holbertonschool-simple_shell/blob/main/printer.c) | void print_prompt(); <br>void print_command_not_found_error(); <br>void printenv_with_environ(); | Prints the shell prompt. <br>Prints an error message for a command not found. <br>Prints the environment variables. |
| [`reader.c`](https://github.com/WarrenTheRabbit/holbertonschool-simple_shell/blob/main/reader.c) | InputBuffer *new_input_buffer(); <br>char *readline(); <br>void close_input_buffer(); | Returns a small wrapper around the state needed by getline(). <br>Reads a line of input into a buffer and excludes the newline character. <br>Frees the memory allocated by new_input_buffer() and readline(). |
| [`scanner.c`](https://github.com/WarrenTheRabbit/holbertonschool-simple_shell/blob/main/scanner.c) | void initialise_command_array(); | Tokenizes the input line into separate arguments using space as the delimiter. |
| [`string_utilities.c`](https://github.com/WarrenTheRabbit/holbertonschool-simple_shell/blob/main/string_utilities.c) | void trim(); | Modifies the input string by removing leading and trailing whitespace characters (as determined by the isspace function). |

## System and Library calls

This table lists all the System calls `2` and library calls `3` used in this project, you could read more by clicking on their respective manual pages.

| Name | Manual Page | Brief Description |
| --- | --- | --- |
| `fork` | [man 2 fork](https://man7.org/linux/man-pages/man2/fork.2.html) | fork() function creates a new process by duplicating the calling process. The new process is referred to as the child process. The calling process is referred to as the parent process. |
| `perror` | [man 3 perror](https://man7.org/linux/man-pages/man3/perror.3.html) | perror() function produces a message on standard error describing the last error encountered during a call to a system or library function. |
| `execve` | [man 2 execve](https://man7.org/linux/man-pages/man2/execve.2.html) | execve() function allows a process to execute another program. |
| `waitpid` | [man 2 waitpid](https://man7.org/linux/man-pages/man2/waitpid.2.html) | waitpid() function suspends execution of the calling thread until a child specified by pid argument has changed state. |
| `stat` | [man 2 stat](https://man7.org/linux/man-pages/man2/stat.2.html) | stat() function display detailed information about a file or file system. |
| `exit` | [man 3 exit](https://man7.org/linux/man-pages/man3/exit.3.html) | exit() function causes the current shell or script to exit or terminate. |
| `isatty` | [man 3 isatty](https://man7.org/linux/man-pages/man3/isatty.3.html) | isatty() function tests whether a file descriptor refers to a terminal. |
| `malloc` | [man 3 malloc](https://man7.org/linux/man-pages/man3/malloc.3.html) | malloc() function dynamically allocates a single large block of memory with the specified size. |
| `getline` | man 3 getline | getline() function reads an entire line from input, storing the address of the buffer containing the text into a pointer. |
| `free` | [man 3 free](https://man7.org/linux/man-pages/man3/free.3.html) | free() function frees the memory space from the heap, which must have been returned by a previous call to malloc(), calloc(), or realloc(). |
| `strtok` | [man 3 strtok](https://man7.org/linux/man-pages/man3/strtok.3.html) | strtok() function is to break a string into a series of tokens based on a specified delimiter. |

## Example of Use
Interactive mode:

Non-interactive mode:


## Installation

First, clone this repository to your local machine:

```bash
$ git clone https://github.com/WarrenTheRabbit/holbertonschool-simple_shell.git
```
Then, go to the repository folder:

```bash
$ cd holbertonschool-simple_shell
```
To use the shell compile it using the provided Makefile:

```bash
$ make
```
Then, run the executable:                                             
                                                                      
```bash                                                               
$ ./simple_shell                                                      
```
In interactive mode, you can enter commands directly into the shell. I
n non-interactive mode, you can use pipes or input redirection to feed
 commands to the shell. 

## Authors

- Warren Markham warren.markham@gmail.com
- Nobuhiro Funahashi tw200green@gmail.com
- Tingru Liu tingru0515@gmail.com
## Bugs

Report bugs on the GitHub Issues page.

## Contributing

Contributions are welcome! Fork the repository, create a branch, make your changes, and submit a pull request.

## License

This project is released under the MIT License - see the [LICENSE](https://github.com/WarrenTheRabbit/holbertonschool-simple_shell/blob/main/LICENSE) file for details.

## Acknowledgements

This project was developed as part of the curriculum for [Holberton School](https://www.holbertonschool.com/), a campus-based full-stack software engineering program. We would like to acknowledge the guidance and support received from our peers and mentors during the development of this Simple Shell project.
