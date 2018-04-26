#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

long getNumericResponse() {

    char *dummyresult;
    char *end_ptr;
    char buffer[MAX_RESPONSE];
    long response;

    dummyresult = fgets(buffer, sizeof(buffer), stdin);
    if (dummyresult){}
    response = strtol(buffer, &end_ptr, 10);

    if (end_ptr == buffer) {
        // not numeric input
        return 0;
    }

    return response;
}
