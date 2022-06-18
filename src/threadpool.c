#ifndef __unix__
#error This program should be complied and work in UNIX-LIKE platform.
#endif

#include <pthread.h>
#include <stdlib.h>
#include "threadpool.h"

threadpool *threadpool_create(size_t max_count)
{
    return NULL;
}

void threadpool_destroy(threadpool *thread_pool)
{
}