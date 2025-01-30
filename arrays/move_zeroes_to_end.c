#include <stdio.h> 

void zeroes_to_end(int arr[], int len) {
    int count=0;

    for(int i=0; i<len; i++){
        if(arr[i] != 0) {
            arr[count++] = arr[i];
        }
    }

    while (count<len){
        arr[count++] = 0;
    }
}

int main() {
    int arr[] = {1,2,0,3,0,4,5,0,2,0,9,10};
    int len = sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    zeroes_to_end(arr, len);

    for(int i=0; i<len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}