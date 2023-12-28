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
void trim(char *const a)
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
/**
 * get_first_string - modify char pointer to be the string until the delimiter.
 *
 * @str: The input string to modify.
 * @delimiter: dividing string.
 *
 * Return: void
 */

void get_first_string(char *const str, char delimiter)
{
	char *delimiter_pos;

	if (str == NULL || *str == '\0')
	{
		return;
	}

	delimiter_pos = strchr(str, delimiter);

	if (delimiter_pos != NULL)
	{
		*delimiter_pos = '\0';
	}
}
