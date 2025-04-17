#include <assert.h>
#include <stdio.h>
#include "stack.h"
void test_stack_overflow() {
    // Test stack overflow (for static stack with limited size)
    stack *s = stack_new();
    assert(s != NULL);

    // Assuming the stack has a fixed size of 5 for example purposes
    s = stack_push(s, 1);
    s = stack_push(s, 2);
    s = stack_push(s, 3);
    s = stack_push(s, 4);
    s = stack_push(s, 5);

    // Now, pushing more than the capacity should result in an error or stack overflow condition
    // Assuming overflow condition is -1 or a special error value
    s = stack_push(s, 6);
    assert(stack_peek(s) == 5); // The top should still be 5
    assert(stack_len(s) == 5); // Stack size should not exceed the limit

    // Free the stack
    stack_free(s);
}

void test_multiple_pop() {
    // Pop multiple times
    stack *s = stack_new();
    assert(s != NULL);

    s = stack_push(s, 10);
    s = stack_push(s, 20);
    s = stack_push(s, 30);

    assert(stack_peek(s) == 30);
    assert(stack_len(s) == 3);

    // Pop once
    assert(stack_pop(s) == 30);
    assert(stack_peek(s) == 20);
    assert(stack_len(s) == 2);

    // Pop again
    assert(stack_pop(s) == 20);
    assert(stack_peek(s) == 10);
    assert(stack_len(s) == 1);

    // Pop last element
    assert(stack_pop(s) == 10);
    assert(stack_len(s) == 0); // Now the stack should be empty

    // Free the stack
    stack_free(s);
}

void test_peek_after_pop() {
    // Peek after popping
    stack *s = stack_new();
    assert(s != NULL);

    s = stack_push(s, 10);
    s = stack_push(s, 20);
    s = stack_push(s, 30);

    // Peek before popping
    assert(stack_peek(s) == 30);

    // Pop once
    assert(stack_pop(s) == 30);

    // Peek again, after popping
    assert(stack_peek(s) == 20);

    // Free the stack
    stack_free(s);
}

void test_popping_more_than_pushed() {
    // Pop more than the number of elements pushed
    stack *s = stack_new();
    assert(s != NULL);

    s = stack_push(s, 10);

    // Pop once
    assert(stack_pop(s) == 10);

    // Now popping again should return the error value (-1)
    assert(stack_pop(s) == -1);

    // Free the stack
    stack_free(s);
}

void test_large_stack() {
    // Test handling of large stack size
    stack *s = stack_new();
    assert(s != NULL);

    // Push a large number of elements (assuming no static size limit)
    for (int i = 0; i < 10000; i++) {
        s = stack_push(s, i);
    }

    assert(stack_len(s) == 10000); // Check the length after pushing 10,000 elements

    // Free the stack
    stack_free(s);
}

int main() {
    // Run all tests
    test_stack_create_and_push();
    test_stack_pop();
    test_stack_create_with_array();
    test_empty_stack_pop();
    test_stack_peek_empty();
    test_stack_overflow();
    test_multiple_pop();
    test_peek_after_pop();
    test_popping_more_than_pushed();
    test_large_stack();

    printf("All tests passed successfully!\n");
    return 0;
}
