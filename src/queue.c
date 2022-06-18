#include "queue.h"
#include <stdlib.h>

queue *queue_create(size_t max_len)
{
    queue *ret = (queue *)malloc(sizeof(queue));
    ret->max_length = max_len;
    ret->head = NULL;
}

bool queue_empty(queue *que)
{
    if (que != NULL & que->length == 0)
        return true;
    return false;
}

data_pointer *queue_pop(queue *que)
{
    queue_node *prev_head_node = que->head;
    data_pointer *prev_head_data = NULL;
    if (que->length <= 0 | prev_head_node == NULL)
        return NULL;
    que->head = prev_head_node->next;
    que->length--;
    prev_head_data = prev_head_node->data_field;
    queue_node_destroy(prev_head_node);
    return prev_head_data;
}

void queue_push(queue *que, data_pointer *ptr)
{
    queue_node *new_node = queue_node_create(ptr);
}

data_pointer *queue_at(queue *que, size_t index)
{
    if (index > (que->length) - 1)
        return NULL;
    for (int i = 0; i != index; i++)
    {
    }
}

size_t queue_length(queue *que)
{
    return que->length;
}

void queue_destroy(queue *que)
{
    if (que == NULL)
        return;
    free(que);
}

void queue_node_destroy(queue_node *que_node)
{
    if (que_node == NULL)
        return;
    free(que_node);
}

queue_node *queue_node_create(data_pointer *ptr)
{
    queue_node *ret = (queue_node *)malloc(sizeof(queue_node));
    ret->data_field = ptr;
    ret->next = NULL;
    ret->prev = NULL;
    return ret;
}