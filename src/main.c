#ifndef __unix__
#error This program should be complied and work in UNIX-LIKE platform.
#endif

#include <pthread.h>
#include <stdio.h>

int main()
{
    printf("this is linux");
    return 0;
}