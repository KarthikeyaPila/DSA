#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linked_list_operations.h"

int main(){
  Node *head = malloc(sizeof(Node));
  if(head==NULL){
    printf("Memory allocation failed.\n");
    return -1;
  }

  create(head);

  printf("Linked List: ");
  display(head);

  append(&head, 10);
  append(&head, 20);
  append(&head, 30);

  printf("Updated Linked List: ");
  display(head);

  delete_node(&head, 1);
  printf("After deleting 1st node: ");
  display(head);

  int size = count(head);
  printf("The list has %d number of nodes\n", size);

  printf("\nSorting the Linked List...\n");
  bubble_sort(&head);
  printf("Sorted Linked List: ");
  display(head);

  clear_list(&head);
  assert(head == NULL);

  return 0;
}
