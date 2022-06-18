#ifndef _THREADPOOL_H
#define _THREADPOOL_H

#include <stdlib.h>
#include <pthread.h>
#include "queue.h"

#define THREADPOOL_MAX_COUNT 200

typedef int thread_status;
#define THREAD_STATUS_BUSY 0x17
#define THREAD_STATUS_IDLE 0x18

typedef struct threadpool
{
    size_t max_count;
    queue *available_thread_queue;
    size_t available_thread_count;
} threadpool;

typedef struct thread_work
{
    thread_status status;
    pthread_t tid;
} thread_work;

threadpool *threadpool_create(size_t max_count);

thread_status thread_work_create();

#endif