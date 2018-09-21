#include "partition.h"

int randomSelect(int *A, int p, int r, int i) {
    if (p == r)
        return A[p];
    int q = randomPartition(A, p, r);
    int k = q - p + 1;
    if (i == k)
        return A[q];
    else if (i < k)
        return randomSelect(A, p, q - 1, i);
    else
        return randomSelect(A, q + 1, r, i - k);
}

int main(void) {
    int *A, length, index;
    printf("Please input the length of array: ");
    scanf("%d", &length);
    A = (int *)malloc(sizeof(int) * length);
    printf("Input the number of index: ");
    scanf("%d", &index);
    puts("Please input the array: ");
    for (int i = 0; i < length; i++) {
        scanf("%d", &A[i]);
    }
    printf("The %d smallest number is: %d\n", index, randomSelect(A, 0, length - 1, index));
    return 0;
}