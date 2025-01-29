#include <stdio.h> 

void get_alternate(int arr[], int n) {
    for(int i=0; i<n; i+=2){
        printf("%d ", arr[i]);    
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int len = sizeof(arr)/sizeof(arr[0]);

    get_alternate(arr, len);

    return 0;
}