
#include "get_next_line.h"
#include <stdio.h>
int                main(void)
{
    int            i;
    char        *s;

    i = 0;
    s = NULL;
    while (get_next_line(0, &s))
    {
        printf("%d : %s$\n", ++i, s);
        free(s);
    }
    return (0);
}
