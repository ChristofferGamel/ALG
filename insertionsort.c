#include <stdio.h>

int main() {
    int A[] = {1, 5, 3, 6, 3, 7, 0, 7, 4, 23, 1, 5};
    int j;
    int i;
    int key;

    for (j = 1; j < sizeof(A) / sizeof(int); j++) {
        key = A[j];
        i = j - 1;
        while (i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
    }

    for (i = 0; i < sizeof(A) / sizeof(int); i++) {
        printf("%d ", A[i]);
    }
    return 0;
}
