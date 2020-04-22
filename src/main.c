#include <stdio.h>
#include "example.h"

int real_main(int argc, char ** argv)
{
    int i = 0;

    printf("This is main!!!\r\n");
    while( taskFunction(i++) == 66);

    return 1;
}

#ifndef TEST
int main(int argc, char ** argv)
{
    return real_main(argc, argv);
}
#endif
