#include "partition.h"

void quicksort(int *A, int p, int r) {
    if (p < r) {
        int q = randomPartition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
    return;
}

int main(void) {
    int *A, length;
    printf("Please input the length of array: ");
    scanf("%d", &length);
    A = (int *)malloc(sizeof(int) * length);
    puts("Please input the array: ");
    for (int i = 0; i < length; i++) {
        scanf("%d", &A[i]);
    }
    quicksort(A, 0, length - 1);
    puts("The sorted array is: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", A[i]);
    }
    puts("");
    free(A);
    return 0;
}

