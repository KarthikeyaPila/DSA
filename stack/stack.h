#ifndef _STACK_H_
#define _STACK_H_
#include <stddef.h>

typedef struct stack stack; 

// CRUD
// Create
stack *stack_new();
stack *stack_create(int *arr, size_t len);

// Read
int stack_peek(stack *stack);
size_t stack_len(stack *stack);

// Update
int stack_pop(stack *stack);
stack* stack_push(stack *stack, int value);

// Delete
void stack_free(stack *stack);
#endif
