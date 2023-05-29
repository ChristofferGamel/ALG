/*
Heapsort, as part of lecture 5
*/

#include <stdio.h>

void heapsort(int arr[], int n){
    // Build a max heap
    for(int i = n/2-1;i >= 0; i--){
        heapify(arr, n, i);
    }

    // Extract elements from the heap, one by one
    for(int i = n-1; i > 0; i--){
        // Swap the root (max) with the current last element
        swap(&arr[0], &arr[i]);

        // Reduce the heap size and heapify the root element
        heapify(arr, i, 0);
    }
}

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i +2;

    // If left child is larger than the root
    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }

    // If the right child is larger than the largest so far
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }

    // If the largest is not the root
    if(largest != i){
        swap(&arr[i], &arr[largest]);
        
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    heapsort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}