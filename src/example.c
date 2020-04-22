#include "example.h"
#include "library.h"

int  taskFunction(int arg)
{
    int retval = 1;

    if (arg == 1)
    {
        retval = libFunction(2);
    }

    return retval;
}

