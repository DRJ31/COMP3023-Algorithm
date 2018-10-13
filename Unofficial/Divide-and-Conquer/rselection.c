#include "func.h"

int main(void)
{
    int *A, length, index;
    printf("Please input the length of array: ");
    scanf("%d", &length);
    A = (int *)malloc(sizeof(int) * length);
    puts("Please input the array: ");
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &A[i]);
    }
    printf("Input the number of index: ");
    scanf("%d", &index);
    printf("The %d smallest number is: %d\n", index, randomSelect(A, 0, length - 1, index));
    free(A);
    return 0;
}