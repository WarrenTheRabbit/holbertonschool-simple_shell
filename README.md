# holbertonschool-simple_shell
Simple Shell is a minimalistic UNIX command line interpreter developed as part of the Holberton School curriculum. The shell allows users to execute commands in both interactive and non-interactive modes.

## Table of Contents

- [Description](#description)
- [Features](#features)
- [Usage](#usage)
- [Compilation](#compilation)
- [Testing](#testing)
- [Authors](#authors)
- [Bugs](#bugs)
- [Contributing](#contributing)
- [License](#license)

## Description

The Simple Shell project aims to create a basic command-line interpreter that mimics some of the functionalities of the standard Unix shell (/bin/sh). It is designed to handle simple commands, execute executables, and provide a basic environment for command execution.

## Flowchart

## File Structure

This table give a brief description of the files used for the simple shell to work, click on the names to get the source code.

| File | Content | Description |
| --- | --- | --- |
| `[shell.h](https://github.com/WarrenTheRabbit/holbertonschool-simple_shell/blob/main/shell.h)` | Header of the project | Contains the structures, prototypes, macros and external variables of the project. |
| `[main.c](https://github.com/WarrenTheRabbit/holbertonschool-simple_shell/blob/main/main.c)` | void process_command(); <br>int main(); | Mainloop, receive input from the Command Line Interface parse and execute it. |
| `[evaluator.c](https://github.com/WarrenTheRabbit/holbertonschool-simple_shell/blob/main/evaluator.c)` | int is_exit(); <br>int is_env(); <br>int is_eof(); <br>int is_empty(); <br>int evaluate(); | Check if the input string is "exit"/ "env"/ NULL/ empty. <br>Evaluates the input string and determines the command type. |
| `[is_executable.c](https://github.com/WarrenTheRabbit/holbertonschool-simple_shell/blob/main/is_executable.c)` | int is_executable(); | Check if a file is executable. |
| `[executor.c](https://github.com/WarrenTheRabbit/holbertonschool-simple_shell/blob/main/executor.c)` | int execute(); | Execute a command in a child process. |
| `[parser.c](https://github.com/WarrenTheRabbit/holbertonschool-simple_shell/blob/main/parser.c)` | void parse(); | Trim whitespace from the given command. |
| `[printer.c](https://github.com/WarrenTheRabbit/holbertonschool-simple_shell/blob/main/printer.c)` | void print_prompt(); <br>void print_command_not_found_error(); <br>void printenv_with_environ(); | Prints the shell prompt. <br>Prints an error message for a command not found. <br>Prints the environment variables. |
| `[reader.c](https://github.com/WarrenTheRabbit/holbertonschool-simple_shell/blob/main/reader.c)` | InputBuffer *new_input_buffer(); <br>char *readline(); <br>void close_input_buffer(); | Returns a small wrapper around the state needed by getline(). <br>Reads a line of input into a buffer and excludes the newline character. <br>Frees the memory allocated by new_input_buffer() and readline(). |
| `[scanner.c](https://github.com/WarrenTheRabbit/holbertonschool-simple_shell/blob/main/scanner.c)` | void initialise_command_array(); | Tokenizes the input line into separate arguments using space as the delimiter. |
| `[string_utilities.c](https://github.com/WarrenTheRabbit/holbertonschool-simple_shell/blob/main/string_utilities.c)` | void trim(); | Modifies the input string by removing leading and trailing whitespace characters (as determined by the isspace function). |

## System and Library calls

## Example of Use

To use the shell, compile it using the provided Makefile:

```bash
$ make
```

Then, run the executable:

```bash
$ ./simple_shell
```

In interactive mode, you can enter commands directly into the shell. In non-interactive mode, you can use pipes or input redirection to feed commands to the shell.

## Installation

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
