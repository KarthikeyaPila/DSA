#include <assert.h>
#include <stdio.h>
#include "../queue/queue.h"

void test_large_enqueue_dequeue() {
    Queue* q = queue_new();

    for (int i = 0; i < 1000; i++) {
        queue_enqueue(q, i);
        assert(queue_peek(q) == 0);  // Always front
    }
    assert(queue_size(q) == 1000);

    for (int i = 0; i < 1000; i++) {
        assert(queue_dequeue(q) == i);
    }

    assert(queue_is_empty(q));
    queue_free(q);
}

void test_alternate_enqueue_dequeue() {
    Queue* q = queue_new();
    
    queue_enqueue(q, 1);
    queue_enqueue(q, 2);
    assert(queue_dequeue(q) == 1);
    queue_enqueue(q, 3);
    assert(queue_peek(q) == 2);
    assert(queue_dequeue(q) == 2);
    assert(queue_dequeue(q) == 3);
    assert(queue_dequeue(q) == -1);  // Empty
    assert(queue_is_empty(q));

    queue_free(q);
}

void test_null_queue_behavior() {
    assert(queue_peek(NULL) == -1);
    assert(queue_dequeue(NULL) == -1);
    assert(queue_size(NULL) == 0);
    assert(queue_is_empty(NULL));
    assert(queue_enqueue(NULL, 10) == NULL);

    // Should not crash
    queue_free(NULL);
}

void test_create_from_array() {
    int arr[] = {10, 20, 30, 40};
    Queue* q = queue_create(arr, 4);

    assert(queue_size(q) == 4);
    assert(queue_peek(q) == 10);
    assert(queue_dequeue(q) == 10);
    assert(queue_dequeue(q) == 20);
    assert(queue_dequeue(q) == 30);
    assert(queue_dequeue(q) == 40);
    assert(queue_is_empty(q));

    queue_free(q);
}

int main() {
    test_large_enqueue_dequeue();
    test_alternate_enqueue_dequeue();
    test_null_queue_behavior();
    test_create_from_array();

    printf("All advanced queue tests passed! ✅\n");
    return 0;
}
