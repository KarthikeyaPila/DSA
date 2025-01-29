// Given an array arr[] of size n, the task is to find all the Leaders in the array. 
//An element is a Leader if it is greater than or equal to all the elements to its right side. 

#include <stdio.h>
#include <stdlib.h>

void leader(int arr[], int len) {

    int* result = (int*)malloc(len* sizeof(int));
    int count = 0;

    int max = arr[len-1];
    result[count++] = max;

    for (int i=len-2; i>=0; i--) {
        if(arr[i] > max) {
            max = arr[i];
            result[count++] = max;
        }
    }

    for (int i=count-1; i>=0; i--) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
}

int main() {
    int arr[] = {16, 17, 4, 3, 5, 2, 1};
    int len = sizeof(arr)/sizeof(arr[0]);

    leader(arr, len);
    
    return 0;
}