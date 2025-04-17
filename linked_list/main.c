#include <assert.h>
#include <stdio.h>
#include "linked_list.c"

void test_list_new_and_len() {
    list* l = list_new();
    assert(l == NULL);
    assert(list_len(l) == 0);
    list_free(l);
}

void test_list_create_empty() {
    int arr[] = {};
    list* l = list_create(arr, 0);
    assert(l == NULL);
    list_free(l);
}

void test_list_create_and_get() {
    int arr[] = {10, 20, 30, 40};
    list* l = list_create(arr, 4);
    assert(list_len(l) == 4);
    assert(list_get(l, 0) == 10);
    assert(list_get(l, 3) == 40);
    list_free(l);
}

void test_list_insert_head_tail_middle() {
    list* l = list_new();
    l = list_insert(l, 0, 10);  // insert at head
    assert(list_len(l) == 1 && list_get(l, 0) == 10);

    l = list_insert(l, 1, 30);  // insert at tail
    assert(list_len(l) == 2 && list_get(l, 1) == 30);

    l = list_insert(l, 1, 20);  // insert in middle
    assert(list_len(l) == 3 && list_get(l, 1) == 20 && list_get(l, 2) == 30);

    list_free(l);
}

void test_list_insert_out_of_bounds() {
    list* l = list_new();
    l = list_insert(l, 0, 42); // should insert at head since list is empty
    assert(l != NULL && list_len(l) == 1);
    list_free(l);
}

void test_list_update_and_return_value() {
    int arr[] = {5, 15, 25};
    list* l = list_create(arr, 3);
    int prev = list_update(l, 1, 100);
    assert(prev == 5);
    assert(list_get(l, 1) == 100);
    list_free(l);
}

void test_list_remove_head_middle_tail() {
    int arr[] = {1, 2, 3, 4};
    list* l = list_create(arr, 4);

    int val = list_remove(&l, 0); // remove head
    assert(val == 1 && list_len(l) == 3 && list_get(l, 0) == 2);

    val = list_remove(&l, 1); // remove from middle
    assert(val == 3 && list_len(l) == 2 && list_get(l, 1) == 4);

    val = list_remove(&l, 1); // remove tail
    assert(val == 4 && list_len(l) == 1);

    list_free(l);
}

void test_list_sort_already_sorted() {
    int arr[] = {1, 2, 3, 4, 5};
    list* l = list_create(arr, 5);
    l = list_sort(l);
    for (int i = 0; i < 5; ++i) {
        assert(list_get(l, i) == arr[i]);
    }
    list_free(l);
}

void test_list_sort_reverse() {
    int arr[] = {5, 4, 3, 2, 1};
    list* l = list_create(arr, 5);
    l = list_sort(l);
    for (int i = 0; i < 5; ++i) {
        assert(list_get(l, i) == i + 1);
    }
    list_free(l);
}

void test_list_sort_duplicates() {
    int arr[] = {3, 2, 3, 1, 2};
    list* l = list_create(arr, 5);
    l = list_sort(l);
    int expected[] = {1, 2, 2, 3, 3};
    for (int i = 0; i < 5; ++i) {
        assert(list_get(l, i) == expected[i]);
    }
    list_free(l);
}

void test_list_remove_out_of_bounds() {
    int arr[] = {1, 2, 3};
    list* l = list_create(arr, 3);
    int val = list_remove(&l, 5); // should print error and return 0
    assert(val == -1 && list_len(l) == 3);
    list_free(l);
}

void test_list_free_null() {
    list* l = NULL;
    list_free(l); // shouldn't crash
}

void test_list_single_element() {
    list* l = list_new();
    l = list_insert(l, 0, 10);  // Insert a single element
    assert(list_len(l) == 1);
    assert(list_get(l, 0) == 10);
    
    int prev = list_update(l, 0, 20);  // Update the only element
    assert(prev == 10);
    assert(list_get(l, 0) == 20);
    
    int val = list_remove(&l, 0);  // Remove the only element
    assert(val == 20 && list_len(l) == 0);
    list_free(l);
}

void test_list_insert_multiple_head() {
    list* l = list_new();
    l = list_insert(l, 0, 10);  // insert at head
    l = list_insert(l, 0, 20);  // insert at head
    l = list_insert(l, 0, 30);  // insert at head
    assert(list_len(l) == 3);
    assert(list_get(l, 0) == 30);
    assert(list_get(l, 1) == 20);
    assert(list_get(l, 2) == 10);
    list_free(l);
}

void test_list_large_size() {
    list* l = list_new();
    for (int i = 0; i < 1000; ++i) {
        l = list_insert(l, i, i+1);  // Insert 1000 elements
    }
    assert(list_len(l) == 1000);
    assert(list_get(l, 0) == 1);
    assert(list_get(l, 999) == 1000);
    list_free(l);
}

void test_list_insert_negative_values() {
    int arr[] = {-10, 5, -20, 15};
    list* l = list_create(arr, 4);
    assert(list_len(l) == 4);
    assert(list_get(l, 0) == -10);
    assert(list_get(l, 1) == 5);
    assert(list_get(l, 2) == -20);
    assert(list_get(l, 3) == 15);
    
    l = list_sort(l);  // Sort the list
    assert(list_get(l, 0) == -20);
    assert(list_get(l, 1) == -10);
    assert(list_get(l, 2) == 5);
    assert(list_get(l, 3) == 15);
    list_free(l);
}

void test_list_all_same_values() {
    int arr[] = {10, 10, 10, 10, 10};
    list* l = list_create(arr, 5);
    assert(list_len(l) == 5);
    
    for (int i = 0; i < 5; ++i) {
        assert(list_get(l, i) == 10);
    }
    
    l = list_sort(l);  // Sorting should keep the list the same
    for (int i = 0; i < 5; ++i) {
        assert(list_get(l, i) == 10);
    }
    list_free(l);
}

void test_list_insert_at_tail() {
    list* l = list_new();
    l = list_insert(l, 0, 10);  // Insert at head
    l = list_insert(l, 1, 20);  // Insert at tail
    l = list_insert(l, 2, 30);  // Insert at tail
    l = list_insert(l, 3, 40);  // Insert at tail
    assert(list_len(l) == 4);
    assert(list_get(l, 0) == 10);
    assert(list_get(l, 1) == 20);
    assert(list_get(l, 2) == 30);
    assert(list_get(l, 3) == 40);
    list_free(l);
}

void test_list_sort_empty() {
    list* l = list_new();
    l = list_sort(l);  // Sorting an empty list
    assert(l == NULL);  // Should still be NULL
    list_free(l);
}

void test_list_remove_all() {
    int arr[] = {1, 2, 3, 4, 5};
    list* l = list_create(arr, 5);
    
    for (int i = 0; i < 5; ++i) {
        int val = list_remove(&l, 0);  // Remove from the head
        assert(val == i+1 && list_len(l) == 4-i);
    }
    list_free(l);  // List should be empty now
}

int main() {
    test_list_new_and_len();
    test_list_create_empty();
    test_list_create_and_get();
    test_list_insert_head_tail_middle();
    test_list_insert_out_of_bounds();
    test_list_update_and_return_value();
    test_list_remove_head_middle_tail();
    test_list_remove_out_of_bounds();
    test_list_free_null();
    test_list_single_element();
    test_list_insert_multiple_head();
    test_list_large_size();
    test_list_insert_negative_values();
    test_list_all_same_values();
    test_list_insert_at_tail();
    test_list_sort_empty();
    test_list_remove_all();

    printf("✅ All advanced edge case tests passed!\n");
    return 0;
}
