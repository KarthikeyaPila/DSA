//Given an array of positive integers arr[] of size n, the task is to find second largest distinct element in the array.

#include <stdio.h> 

int second_lar (int arr[], int n) {
    int lar=-1, sec_lar=-1 ;

    for (int i=0; i<n; i++) {
        if(arr[i] > lar) {
            sec_lar = lar;
            lar = arr[i];
        } else if(arr[i] < lar && arr[i] > sec_lar) {
            sec_lar = arr[i];
        }
    }

    return sec_lar;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 100};
    int len = seizeof(arr)/sizeof(arr[0]);

    int sec_lar = second_lar(arr, len);

    printf("the second largest element is: %d\n", sec_lar);

    return 0;
}