#include <stdio.h> 
#define len(arr) sizeof(arr)/sizeof(arr[0])

void print_arr(int *arr, int len){
    for(int i=0; i<len; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return;
}

void bubble_sort(int *arr, int len){
    for(int i=0; i<len; i++){
        for(int j=0; j<len-1; j++){
            if(arr[j+1] < arr[j]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    return;
}

int main(){
    int arr[] = {64, 25, 12, 22, 11, -1, -143};

    printf("original array: ");
    print_arr(arr, len(arr));

    bubble_sort(arr, len(arr));

    printf("sorted array: ");
    print_arr(arr, len(arr));

    return 0;
}

