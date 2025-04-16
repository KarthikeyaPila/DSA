#include <stdio.h> 
#include <stdlib.h> 
#include <stddef.h>

typedef struct list{
    struct list* next;
    int value;
} list; 


// Create: 

// Create a new linked list
list* list_new(){
    return NULL;
}

//make a list with an array.
list* list_create(int *arr, size_t len){
    list* head = malloc(sizeof(list));
    struct list *current = head;
    int value;

    for(int i=0; i<len; i++){
        current->value = arr[i];
        if(i == len-1){
            current->next = NULL;
        }
        else {
            current->next = malloc(sizeof(struct list));
        }
        current = current->next;
    }

    return head;
}

// insert a new node at a given node_number.
list* list_insert(list* list, size_t index, int val){
    struct list *current = list;
   
    for(int i=0; i<index-1; i++){
        current = current->next;

        if(current == NULL){
            printf("You've reached the end.\n");
            return list;
        }
    }

    struct list *temp = malloc(sizeof(struct list));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return list;
    }

    temp->value = val;
    temp->next = current->next;        
    current->next = temp;

    return list; 
}


// Read: 

// get the index value
int list_get(list* list, size_t index){
    int x = 0; 
    int result; 
    do{
        list = list->next; 
        x++;
    }while(x!=index);

    result = list->value;
    return result; 
}

// return the size of the linked list
size_t list_len(list* list){
    
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
    int previous_val = value; 

    struct list *current = list;
    
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
int  list_remove(list* list, size_t index){
    struct list *current = list;
    int val;

    if(index == 0){  // Head node removal
        struct list *temp = list;
        val = list->value;
        list = (list)->next;
        free(temp);
        return val;
    }

    for(int i=0; i<index-1; i++){
        if(current == NULL || current->next == NULL) {
            printf("Out of bounds\n");
            return 0;
        }
        current = current->next;
    }

    struct list *temp = current->next;

    if(temp == NULL) {  // delete beyond the last node
        printf("Out of bounds\n");
        return 0;
    }

    val = temp->value;
    current->next = temp->next;
    
    free(temp);
    return val; 
}

// free the whole linked list.
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
        return;
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

int main(){
    int arr[] = {1,234,1,234,1,51,25,16,1};
    size_t len = sizeof(arr)/sizeof(arr[0]);

    list* l = list_new();
    list_print(l);

    l = list_create(arr, len);
    list_print(l);

    l = list_insert(l, 4, 10);
    list_print(l);

    int get_index = 4;
    printf("value at index: %d = %d\n", get_index, list_get(l, get_index));    

    printf("the linked list is %zu elements long.\n", list_len(l));

    int update_to_value = 100;
    int updated_num = list_update(l, 4,update_to_value);
    printf("updated the value from %d to %d.\n", updated_num, list_get(l, 4));
    list_print(l);

    int removal_index = 4;
    printf("removed index: %d with value: %d.\n", removal_index, list_remove(l, removal_index));
    list_print(l);

    removal_index = 5;
    printf("removed index: %d with value: %d.\n", removal_index, list_remove(l, removal_index));
    list_print(l);

    list_sort(l);
    list_print(l);

    list_free(l);
    return 0;
}