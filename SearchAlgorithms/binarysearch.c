#include <stdio.h>

int srch(int l,int r, int arr[], int target){
    int mid;
    while(l <= r){
        mid = (r + l) / 2; //
        if (arr[mid] == target){
            return mid;
        } else if (arr[mid] < target){
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1, 6, 8, 14, 22, 78, 114, 289, 301}; //sorted array
    int l = 0; //left
    int r = sizeof(arr)/sizeof(int)-1; //right
    
    int target = 289;

    int ret = srch(l, r, arr, target);
    printf("The target: %d, is found at the index: %d\n", target, ret, arr);
    return 0;
    
}

