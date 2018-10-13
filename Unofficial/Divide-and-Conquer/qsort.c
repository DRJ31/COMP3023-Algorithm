#include "func.h"

void rquicksort(int *A, int p, int r)
{
    if (p < r)
    {
        int q = partition(A, p, randomPos(p, r), r);
        rquicksort(A, p, q - 1);
        rquicksort(A, q + 1, r);
    }
    return;
}

void dquicksort(int *A, int p, int r)
{
    if (p < r)
    {
        int q = partition(A, p, findMedian(A, p, r), r);
        dquicksort(A, p, q - 1);
        dquicksort(A, q + 1, r);
    }
    return;   
}

int main(void)
{
    int *A, *B, length;
    printf("Please input the length of array: ");
    scanf("%d", &length);
    A = (int *)malloc(sizeof(int) * length);
    B = (int *)malloc(sizeof(int) * length);  
    puts("Please input the array: ");
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &A[i]);
        B[i] = A[i];
    }
    rquicksort(A, 0, length - 1);
    dquicksort(B, 0, length - 1);
    puts("The sorted array by random quick sort is: ");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", A[i]);
    }
    puts("");
    puts("The sorted array by deterministic quick sort is: ");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", B[i]);
    }
    puts("");
    free(A);
    return 0;
}
