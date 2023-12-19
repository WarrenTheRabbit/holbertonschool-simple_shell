#include <ctype.h>

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
