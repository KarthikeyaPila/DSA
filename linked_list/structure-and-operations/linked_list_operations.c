#include <stdio.h> 
#include <stdlib.h>
#include "linked_list_operations.h"

void create(struct Node *head){
    struct Node *current = head;
    int value;

    while(1){
        printf("Enter the value: ");
        scanf("%d", &value);

        if (value == -999) {
            current->next = NULL;
            break;
        }

        current->value = value;
        current->next = malloc(sizeof(struct Node));
        if(current->next == NULL){
            printf("Memory allocation failed.\n");
            current->next = NULL;
            break;
        }
        current = current->next;
    }
}

void display(struct Node *head){
    struct Node *temp = head;
    do {
        printf("%d ", temp->value);
        temp = temp->next;
    } while(temp != NULL);
    printf("\n");
}

void delete_node(struct Node **head, int node_num){
    struct Node *current = *head;

    if(node_num == 0){  // Head node removal
        struct Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    for(int i=0; i<node_num-1; i++){
        if(current == NULL || current->next == NULL) {
            printf("Out of bounds\n");
            return;
        }
        current = current->next;
    }

    struct Node *temp = current->next;

    if(temp == NULL) {  // delete beyond the last node
        printf("Out of bounds\n");
        return;
    }

    current->next = temp->next;
    free(temp);
}

void add_at_beginning(struct Node **head, int val){
    struct Node *temp = malloc(sizeof(struct Node));

    if (temp == NULL) {
        printf("Insertion at beginning failed\n");
        return;
    }
    temp->value = val;      
    temp->next = *head;      
    *head = temp;
}

void add_after_n(struct Node *head, int node_num, int val){

    struct Node *current = head;
    
    for(int i=0; i<node_num; i++){
        current = current->next;

        if(current == NULL){
            printf("You've reached the end.\n");
            return;
        }
    }

    struct Node *temp = malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    temp->value = val;
    temp->next = current->next;        
    current->next = temp;

}

void append(struct Node **head, int val){
    struct Node *current = *head;
    struct Node *temp;

    if(*head == NULL){
        current = malloc(sizeof(struct Node));
        if(current == NULL){
            printf("Memory allocation failed.\n");
            return;
        }
        current->next = NULL;
        current->value = val;
        *head = current;
        return;
    }

    while(current->next != NULL){
        current = current->next;
    }

    temp = malloc(sizeof(struct Node));
    if(temp == NULL){
        printf("Memory allocation failed.\n");
        return;
    }
    temp->value = val;
    temp->next = NULL;
    current->next = temp;
}

int count(struct Node *head){
    int size=0;

    while(head != NULL){
        size++;
        head = head->next;
    }

    return size;
}

void clear_list(struct Node **head) {
    struct Node *temp;

    while (*head != NULL) {
        temp = *head;          
        *head = (*head)->next; 
        free(temp);            
    }

    *head = NULL;
}


void bubble_sort(struct Node **head){
    int swapped;
    struct Node *current;
    struct Node *last = NULL;

    if (*head == NULL){
        return;
    }
    
    do {
        swapped = 0;
        current = *head;

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
}
