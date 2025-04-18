#include <stdio.h> 
#define len(arr) sizeof(arr)/sizeof(arr[0])

void print_arr(int *arr, int len){
    for(int i=0; i<len; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return;
}

void insertion_sort(int *arr, int len){
    for(int i=0; i<len; i++){
        int current = arr[i];
        int j=i-1;

        while(j>=0 && arr[j] > current){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = current;
    }

    return;
}

int main(){
    int arr[] = {64, 25, 12, 22, 11, -1, -143};

    printf("original array: ");
    print_arr(arr, len(arr));

    insertion_sort(arr, len(arr));

    printf("sorted array: ");
    print_arr(arr, len(arr));

    return 0;
}

