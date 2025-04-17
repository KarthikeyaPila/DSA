#include <stdio.h> 
#include <stdlib.h> 
#include <stddef.h>

typedef struct list{
    struct list* next;
    int value;
} list; 

void list_free(list* list);
size_t list_len(const list* list);

// Create: 

// Create a new linked list
list* list_new(){
    return NULL;
}

//make a list with an array.
list* list_create(int *arr, size_t len) {
    if(len == 0) {
        return NULL;
    }

    list* head = malloc(sizeof(list));
    list* current = head;

    for (size_t i = 0; i < len; i++) {
        current->value = arr[i];
        if (i < len - 1) {
            current->next = malloc(sizeof(list));
            current = current->next;
        } else {
            current->next = NULL;
        }
    }

    return head;
}

// insert a new node at a given node_number.
list* list_insert(list* list, size_t index, int val) {
    if (index == 0) {
        struct list* new_node = malloc(sizeof(list));
        if (!new_node) {
            printf("Memory allocation failed\n");
            return NULL;
        }
        new_node->value = val;
        new_node->next = list;
        return new_node;
    }

    struct list* current = list;
    for (size_t i = 0; i < index - 1; i++) {
        if (!current) {
            printf("Index out of bounds\n");
            return list;  // No change made to the list
        }
        current = current->next;
    }

    struct list* new_node = malloc(sizeof(list));
    if (!new_node) {
        printf("Memory allocation failed\n");
        return list;
    }
    new_node->value = val;
    new_node->next = current->next;
    current->next = new_node;

    return list;
}



// Read: 

// get the index value
int list_get(list* list, size_t index){
    if (list == NULL){
        return -1;
    }

    size_t x = 0;
    while (list != NULL && x < index) {
        list = list->next;
        x++;
    }

    if (list == NULL){
        return -1;
    }
    
    return list->value;
}


// return the size of the linked list
size_t list_len(const list* list){
    
    size_t size=0;
    while(list != NULL){
        size++;
        list = list->next;
    }
    
    return size;
}

// print the linked list. 
void list_print(list* list){
    
    if(list == NULL){
        printf("the list is void.\n");
        return;
    }

    struct list *temp = list;
    do{
        printf("%d ", temp->value);
        temp = temp->next;
    } while(temp != NULL);
    printf("\n");
    return;
}



// Update: 
// update the value of the given node. 
int list_update(list* list, size_t index, int value){
    
    struct list *current = list;
    int previous_val = current->value; 
    
    for(int i=0; i<index; i++){
        current = current->next;

        if(current == NULL){
            printf("You've reached the end.\n");
            return 0;
        }
    }

    current->value = value;
    return previous_val; 
}

//Delete
int list_remove(list** list, size_t index) {
    if (*list == NULL) {
        printf("The list is empty.\n");
        return -1;
    }

    struct list* current = *list;
    if (index == 0) {
        *list = current->next;
        int removed_val = current->value;
        free(current);
        return removed_val;
    }

    for (size_t i = 0; current != NULL && i < index - 1; i++) {
        current = current->next;
    }

    if (current == NULL || current->next == NULL) {
        printf("Index out of bounds.\n");
        return -1;
    }

    struct list* temp = current->next;
    current->next = temp->next;
    int removed_val = temp->value;
    free(temp);

    return removed_val;
}


void list_free(list* list){
    struct list *temp;

    while (list != NULL) {
        temp = list;          
        list = (list)->next; 
        free(temp);            
    }

    list = NULL;
}
    
// sort the linked list.
list* list_sort(struct list *list){
    int swapped;
    struct list *current;
    struct list *last = NULL;

    if (list == NULL){
        return NULL;
    }
    
    do {
        swapped = 0;
        current = list;

        while (current->next != last){
            if (current->value > current->next->value){
                int temp = current->value;
                current->value = current->next->value;
                current->next->value = temp;
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while(swapped);

    return list;
}
