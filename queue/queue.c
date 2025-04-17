#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>
#include "../linked_list/linked_list.h"

typedef struct {
    struct list *head;
    int size;
} Queue; 

Queue* queue_new(){
    Queue* q = malloc(sizeof(Queue));
    q->head = NULL;
    q->size = 0;
    return q;
}

Queue* queue_create(int *arr ,int len){
    Queue* h = queue_new();
    
    h->head = list_create(arr, len);
    h->size = len;

    return h;
}

int queue_peek(Queue* queue){
    if(queue == NULL){
        return -1;
    }

    return list_get(queue->head, 0);
}

size_t queue_size(Queue* queue){
    if(queue == NULL){
        return 0;
    } else {
        return queue->size;
    }
}

bool queue_is_empty(Queue* queue){
    if(queue == NULL || queue->size == 0){
        return true;
    } else {
        return false;
    }
}

int queue_dequeue(Queue* queue){
    if(queue == NULL || queue->size == 0){
        return -1;
    }
    int return_val = list_remove(&(queue->head), 0);
    queue->size = queue->size - 1;

    return return_val;
}

Queue* queue_enqueue(Queue* queue, int val){
    if(queue == NULL){
        return NULL;
    }
    queue->head = list_insert(queue->head, queue->size, val);
    queue->size = queue->size + 1;

    return queue;
}

void queue_free(Queue* queue){  
    if(queue == NULL){
        return;
    }

    list_free(queue->head);

    free(queue);
    return;
}
