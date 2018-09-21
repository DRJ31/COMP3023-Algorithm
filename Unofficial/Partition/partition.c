#include "partition.h"

extern void exchange(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

extern int randomPartition(int* A, int p, int r)
{
	int q = randomPos(p, r);
	exchange(&A[q], &A[r]);
	int x = A[r];
	int i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (A[j] <= x)
		{
			i += 1;
			exchange(&A[i], &A[j]);
		}
	}
	exchange(&A[i + 1], &A[r]);
	return i + 1;
}

extern int randomPos(int p, int r) {
    srand((int) time(0));
    return rand() % (r - p + 1) + p;
}