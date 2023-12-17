all:
	gcc -g -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

clean:
	rm hsh
