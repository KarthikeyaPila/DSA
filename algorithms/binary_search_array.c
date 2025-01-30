// binary search in an array

#include <stdio.h> 

int binary_search(int arr[], int start, int end, int target) {

    if(end >= start) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] > target) {
            return binary_search (arr, start, mid-1 , target);
        }

        else if (arr[mid] < target) {
            return binary_search (arr, mid+1, end, target);
        }
    }

    return -1;

}

int main() {
    int arr[] = { 2, 3, 4, 10, 40 };
    int len = sizeof(arr)/sizeof(arr[0]);
    int x = 10;

    int result = binary_search(arr, 0, len - 1, x);
    
    if (result == -1){
        printf("Element is not present in array\n");
    } else {
        printf("Element is present at index %d\n", result);
    }

    return 0;
}