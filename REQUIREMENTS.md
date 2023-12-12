### Requirements
These are taken from [the project page](https://intranet.hbtn.io/projects/2174).
| Requirement  | Currently enforced by CI/CD? | Enforce how? | 
| --- | --- | --- |
| Compile as `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh` | No | Use flags via Makefile |
| End **files** with newline | No | Makefile runs a script |
| No more than five functions per **file** | No | Makefile runs a script |
| All headers should be include guarded | No| Makefile runs a script |
| Code should use Betty style | No | Makefile invokes `betty` |
| Use system calls only when needed | No | ? |
| No memory leaks | No| Makefile invokes valgrind |
| README.md at root of project | No | Makefile invokes script |



