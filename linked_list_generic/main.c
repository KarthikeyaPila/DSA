#include<stddef.h>
#include<stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Person {
  char name[10];
  int age;
} Person;

// compare function for int
bool cmp(int* a, int* b){
  printf("[cmp] %p:%d %p:%d\n", a, *a, b, *b);
  return (*a > *b);
}

// compare function for Person
bool cmp_age(Person* a, Person* b){
  return (a->age > b->age);
}

// generic sort on any datatype using void*
void* sort(void *arr, size_t size, size_t el_size, void* cmp_fn){
  bool(*cmp)(void*, void*) = cmp_fn;
  size_t* ref_arr = malloc(sizeof(size_t)*size);

  // create an array of references 
  for(size_t i=0; i<size; i++){
    ref_arr[i] = (size_t)arr + (el_size*i);
    printf("0x%zx\n", ref_arr[i]);
  }

  // bubble sort
  for (int i=0; i<size; i++){
    for (int j=0; j<size-i-1; j++){
      if(cmp((void *)ref_arr[j], (void *)ref_arr[j+1])){
        size_t temp = ref_arr[j];
        ref_arr[j] = ref_arr[j+1];
        ref_arr[j+1] = temp;
      }
    }
  }

  return ref_arr;
};

int main() {
  Person p0 = { .name = "josh", .age = 32 };
  Person p1 = { .name = "karthik", .age = 18};
  Person p2 = { .name = "joy", .age = 28 };
  Person p3 = { .name = "penny", .age = 22 };

  Person arr[] = {p0, p1, p2, p3};
  Person **ref_arr = sort(arr, 4, sizeof(Person), &cmp_age);

  // print sorted array
  for(int i=0; i<4; i++){
    printf("%s ", ref_arr[i]->name);
  }
  printf("\n");

  // original array is unaffected 
  for(int i=0; i<4; i++){
    printf("%s ", arr[i].name);
  }
  return 0;
}