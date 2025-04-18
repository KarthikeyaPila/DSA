#include <assert.h>
#include <stdio.h>
#include "hashmap.h"

void run_tests() {
    // Test: Create and insert one item
    map *m = map_new(10);
    assert(map_size(m) == 0);
    map_set(m, 1, 100);
    assert(map_get(m, 1) == 100);
    assert(map_size(m) == 1);

    // Test: Update existing key
    map_set(m, 1, 500);
    assert(map_get(m, 1) == 500);
    assert(map_size(m) == 1); // size should not increase

    // Test: Delete non-existent key
    assert(map_delete(m, 99) == -1);
    assert(map_size(m) == 1);

    // Test: Insert multiple keys and delete one
    map_set(m, 2, 200);
    map_set(m, 3, 300);
    assert(map_size(m) == 3);
    assert(map_delete(m, 2) == 200);
    assert(map_get(m, 2) == -1);
    assert(map_size(m) == 2);

    // Test: Delete then reinsert same key
    map_set(m, 2, 222);
    assert(map_get(m, 2) == 222);
    assert(map_size(m) == 3); // Back to 3

    map_free(m);

    // Test: Collision handling (linear probing)
    map *m2 = map_new(3); // Small capacity to force collisions
    map_set(m2, 3, 33); // hash: 0
    map_set(m2, 6, 66); // hash: 0 (collision)
    map_set(m2, 9, 99); // hash: 0 (collision again)
    assert(map_get(m2, 3) == 33);
    assert(map_get(m2, 6) == 66);
    assert(map_get(m2, 9) == 99);
    map_free(m2);

    // Test: Create from array
    int items[4][2] = {
        {10, 1000},
        {20, 2000},
        {30, 3000},
        {40, 4000}
    };
    map *m3 = map_create(4, items, 8);
    assert(map_get(m3, 10) == 1000);
    assert(map_get(m3, 30) == 3000);
    assert(map_size(m3) == 4);
    map_free(m3);

    printf("✅ All tests passed!\n");
}

int main() {
    run_tests();
    return 0;
}
