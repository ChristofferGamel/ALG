#include <stdio.h>

void merge(int arr[], int l,int mid,int r) {
    int n1 = mid - l +1; //Length of left subarray
    int n2 = r - mid;    //Length of right subarray
    
    //construct temp arrays
    int leftArray[n1];
    int rightArray[n2];
    //copying data into temp arrays
    for(int i = 0; i < n1; i++){
        leftArray[i] = arr[l+i];
    }
    for(int j = 0; j < n2; j++){
        rightArray[j] = arr[mid +1 +j];
    }

    //merging the two subarrays into original arr[]
    int i = 0;
    int j = 0;
    int k = l;

    while(i<n1 && j<n2){
        if(leftArray[i] <= rightArray[j]){
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    //copying the remaining elements of leftArray[], if any
    while(i<n1){
        arr[k] = leftArray[i];
        i++;
        k++;
    }
    //copying the remaining elements of rightArray[], if any
    while(j<n2){
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int l, int r){
    if(l<r){
        int mid = (l+r)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);

        merge(arr, l, mid, r);
    }
}

void printArray(int A[], int size){
    int i;
    for(i=0; i< size; i++){
        printf("%d, ", A[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {5,8,4,3,7,54,3,7,9,9,5,3,23,67,342,34};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    printf("size: %d\n", arr_size);

    printf("Input array is \n");
    printArray(arr, arr_size);
    

    mergeSort(arr, 0, arr_size -1);

    printf("\n Sorted array is \n");
    printArray(arr, arr_size);
    return 0;
}