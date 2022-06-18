#ifndef _EVENT_H
#define _EVENT_H

typedef void *function;

typedef int event_type;
#define EVENT_TYPE_ASYNC 0
#define EVENT_TYPE_SYNC 1

typedef struct event
{
    struct event *callback;
    event_type type;
    function func;
} event;

#endif