#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to perform the Quicksort algorithm
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        // Find the pivot index
        int pivot_index = partition(arr, low, high);

        // Recursively sort the two sub-arrays
        quicksort(arr, low, pivot_index - 1);
        quicksort(arr, pivot_index + 1, high);
    }
}


int main() {
    int arr[] = {9, 2, 5, 1, 7, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, n - 1);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
