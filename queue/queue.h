#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <stddef.h>
#include <stdbool.h> 

typedef struct Queue Queue;

// CRUD

// Create
Queue* queue_new();
Queue* queue_create(int *arr ,int val);

// Read
int queue_peek(Queue* queue);
size_t queue_size(Queue* queue);
bool queue_is_empty(Queue* queue);

// Update
int queue_dequeue(Queue* queue);
Queue* queue_enqueue(Queue* queue, int val);

// Delete
void queue_free(Queue* queue);
#endif