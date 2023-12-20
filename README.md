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

## Features

- Interactive and non-interactive modes
- Command execution (ls, exit, env)
- Error handling for command not found
- Graceful handling of "end of file" condition (Ctrl+D)
- Basic command-line prompt

## Usage

To use the shell, compile it using the provided Makefile:

```bash
$ make
Then, run the executable:
$ ./simple_shell
In interactive mode, you can enter commands directly into the shell. In non-interactive mode, you can use pipes or input redirection to feed commands to the shell.

Compilation

Compile the Simple Shell using the provided Makefile:
$ make
Testing

Test the shell in interactive mode:
$ ./simple_shell
Test the shell in non-interactive mode:
$ echo "/bin/ls" | ./simple_shell
Additional testing information may be provided in the project instructions.

Authors

Warren Markham warren.markham@gmail.com
Nobuhiro Funahashi tw200green@gmail.com
Tingru Liu tingru0515@gmail.com
Bugs

Report bugs on the GitHub Issues page.

Contributing

Contributions are welcome! Fork the repository, create a branch, make your changes, and submit a pull request.

License

This project is released under the MIT License.
Please note that this is a basic README.md, and you might want to customize it further based on your project's specific details and requirements.
