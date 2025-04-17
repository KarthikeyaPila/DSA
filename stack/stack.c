#include <stdio.h> 
#include <stdlib.h> 
#include "../linked_list/linked_list.h"

typedef struct {
    struct list *head;
    int size;
} stack;

// Create
stack *stack_new(){
    stack *s = malloc(sizeof(stack));
    s->head = list_new();
    s->size=0;
    return s;
}

stack *stack_create(int *arr, size_t len){
    stack *s = malloc(sizeof(stack));
    s->head = list_create(arr, len);
    s->size=len;

    return s;
}

// Read
int stack_peek(stack *stack){
    if(stack == NULL){
        return -1;
    }
    return list_get(stack->head, stack->size);
}

size_t stack_len(stack *stack){
    return stack->size;
}

void stack_print(stack *stack){
    list_print(stack->head);
}

// Update
int stack_pop(stack *stack){
    if(stack == NULL){
        return -1;
    }
    int return_val = list_remove(stack->head, stack->size);
    stack->size = (stack->size) - 1;

    return return_val;
}

stack* stack_push(stack *stack, int value){
    list_insert(stack->head, stack->size, value);
    stack->size = (stack->size) + 1;
    return stack;
}

// Delete
void stack_free(stack *stack){
    list_free(stack->head);
    free(stack);
}

int main(){
    int arr[] = {13};

    stack *s = stack_create(arr, 1);

    stack_push(s, 2);
    stack_push(s, 2);
    stack_push(s, 2);
    stack_push(s, 2);
    stack_push(s, 2);

    stack_print(s);

    stack_free(s);
    return 0;
}