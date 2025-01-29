//Given an array arr[], the task is to find the top three largest distinct integers present in the array.

#include <stdio.h> 

void largest_three (int arr[], int n) {

    int fir=-1, sec=-1, thr=-1; 

    for(int i=0; i<n; i++){
        int x = arr[i];

        if(x > fir) {
            thr = sec; 
            sec = fir; 
            fir = x;
        } else if(x > sec && x != fir) {
            thr = sec; 
            sec = x;
        } else if(x > thr && x != fir && x != sec) {
            thr = x;
        }
    }

    printf("first: %d\nsecond: %d\nthird: %d\n", fir, sec, thr);

}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int len = sizeof(arr)/sizeof(arr[0]);
    largest_three (arr, len);

    return 0;
}