#include "event.h"
#include <stdlib.h>
event *event_create(event_type type, function func, function callback)
{
    event *ret = (event *)malloc(sizeof(event));
    ret->callback = callback;
    ret->func = func;
    ret->type = type;
    return ret;
};

void func1()
{
}

void func2()
{
}

void event_test()
{
    event_create(EVENT_TYPE_ASYNC, func1, func2);
}