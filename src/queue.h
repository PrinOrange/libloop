#ifndef _QUEUE_H
#define _QUEUE_H

#include<stdlib.h>
#include<stdbool.h>

typedef void *data_pointer;

typedef struct queue
{
    size_t length;
    size_t max_length;
    struct queue_node *head;
} queue;

typedef struct queue_node
{
    data_pointer *data_field;
    struct queue_node *prev;
    struct queue_node *next;
} queue_node;

//  Functions for queue structure.

queue *queue_create(size_t max_len);
bool queue_empty(queue * que);
data_pointer *queue_pop(queue *que);
void queue_push(queue *que, data_pointer *data);
data_pointer *queue_at(queue *que, size_t index);
size_t queue_length(queue *que);
void queue_destroy(queue *que);

//  Functions for queue_node structure.

queue_node *queue_node_create(data_pointer *ptr);
void queue_node_destroy(queue_node *que_node);
#endif