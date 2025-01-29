// Given an array, arr of n integers, and an integer element x, find whether element x is present in the array. 
//Return the index of the first occurrence of x in the array, or -1 if it doesn’t exist.

#include <stdio.h> 

int search (int arr[], int n, int x) {

    for(int i=0; i<n; i++){
        if (arr[i] == x){
            return i;
        } else {
            continue;
        }
    }

    return -1;
}

int main() {
    
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = sizeof(arr)/sizeof(arr[0]);
    int x = 5;

    int result = search(arr, len, x);

    if (result != -1){
        printf("the index of the number was found to be: %d\n", result);
    } else if (result == -1){
        printf("the required element does not exist in the array.\n");
    }

    return 0;
}