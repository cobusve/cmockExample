#include <stdio.h>
#include "example.h"

int main(void)
{
    int i = 0;

    printf("This is main!!!\r\n");
    while( taskFunction(i++) == 1);

    return 1;
}
