#include <stdio.h> 

int find_largest (int arr[], int n) {
    int num = 0;

    for (int i=0; i<n; i++) {
        if(arr[i] > num) {
            num = arr[i];
        }
    }

    return num;

}

int min_increment(int arr[], int len, int k, int max) {
    int count = 0;

    for(int i=0; i<len; i++) {
        if ((max-arr[i])%k != 0) {
            return -1;
        } 
        count += (max - arr[i])/k; 
    }

    return count;
}

int main() {
    int arr[] = {4, 7, 19, 16};
    int len = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    int max = find_largest(arr, len);
    int num = min_increment(arr, len, k, max);

    printf("min no. of operations: %d\n", num);

    return 0;
}