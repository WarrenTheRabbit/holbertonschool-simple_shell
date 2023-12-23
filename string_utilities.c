#include <ctype.h>
#include "shell.h"

/**
 * trim - Removes leading and trailing whitespace from a string.
 *
 * @a: The input string to be trimmed.
 *
 * Description:
 * This function modifies the input string by removing leading and trailing
 * whitespace characters (as determined by the isspace function).
 *
 * Return: Nothing.
 */
void trim(char * const a)
{
	char *p = a, *q = a;

	if (!a)
		return;

	while (isspace(*q))
		++q;
	while (*q)
		*p++ = *q++;
	*p = '\0';
	while (p > a && isspace(*--p))
		*p = '\0';
}

void get_first_string(char *const str, char delimiter)
{
	char *delimiterPos;
	if (str == NULL || *str == '\0')
	{
		return;
	}

	delimiterPos = strchr(str, delimiter);

	if (delimiterPos != NULL)
	{
		*delimiterPos = '\0';
	}
}
