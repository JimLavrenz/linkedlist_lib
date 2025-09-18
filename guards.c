#include <stdlib.h>
#include <stdio.h>
#include "guards.h"

//Use this as a wrapper to report an error in the event
// malloc can't allocate memory. 
void *OOM_GUARD(void *ptr, char *file, int number)
{
    if (ptr == NULL) {
        fprintf(stderr, "%s:%d Out of Memory", file, number);
        exit(EXIT_FAILURE);
    }
    return ptr;
}
