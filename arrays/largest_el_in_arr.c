//Given an array arr. The task is to find the largest element in the given array. 

#include <stdio.h> 

int find_largest (int arr[], int n) {

    int num;
    
    for (int i=0; i<n; i++) {
        if(arr[i] > num) {
            num = arr[i];
        }
    }

    return num;

}

int main () {
    int arr[] = {10, 20, 30, 40, 123, 50, 60, 70};
    int len = sizeof(arr)/sizeof(arr[0]);

    int largest = find_largest(arr, len);

    printf("the largest element in the array is: %d\n", largest);

    return 0;
}