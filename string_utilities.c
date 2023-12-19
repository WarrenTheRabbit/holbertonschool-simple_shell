#include <ctype.h>

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
