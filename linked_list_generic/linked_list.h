#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include <stddef.h>

typedef struct list list;

// Create
list* list_new();
list* list_create(int* arr, size_t len);
list* list_insert(list* list, size_t index, int value);
// Read
int list_get(list* list, size_t index);
size_t list_len(const list* list);
void   list_print(list* list);
// Update
int list_update(list* list, size_t index, int value);
// Delete
int list_remove(list** list, size_t index);
void list_free(list* list);
// Sort
list* list_sort(list* list);

#endif