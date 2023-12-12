These are ChatGPT's answers to the general learning objectives. 
At the end of the project, we are expected to have our own understanding.

| Goal                                                          | ChatGPT                                                                                     |
|---------------------------------------------------------------|--------------------------------------------------------------------------------------------|
| Who designed and implemented the original Unix operating system | Ken Thompson and Dennis Ritchie at AT&T Bell Labs                                        |
| Who wrote the first version of the UNIX shell                 | Ken Thompson                                                                              |
| Who invented the B programming language                       | Ken Thompson                                                                              |
| Who is Ken Thompson                                           | A computer scientist and co-creator of the Unix operating system, B programming language, and Go language |
| How does a shell work                                         | A command-line interpreter that provides a user interface for access to an operating system's services |
| What is a pid and a ppid                                      | pid is a process identifier; ppid is a parent process identifier                          |
| How to manipulate the environment of the current process       | Use environment variables, which can be set, modified, or removed within a process        |
| What is the difference between a function and a system call    | A function is a set of instructions within a program; a system call is a request for services from the kernel |
| How to create processes                                       | Use system calls like `fork()` or `exec()` in Unix-based systems                          |
| What are the three prototypes of main                         | `int main()`, `int main(int argc, char *argv[])`, and `int main(int argc, char *argv[], char *envp[])` |
| How does the shell use the PATH to find the programs          | The shell searches the directories listed in the PATH environment variable to find executable programs |
| How to execute another program with the execve system call    | Use the `execve` system call with the program's path and the appropriate arguments        |
| How to suspend the execution of a process until one of its children terminates | Use the `wait()` or `waitpid()` system calls                                            |
| What is EOF / “end-of-file”?                                  | A condition in computing that indicates no more data can be read from a data source        |
