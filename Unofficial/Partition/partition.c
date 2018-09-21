#include "partition.h"

void exchange(int a, int b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int partition(int* A, int p, int r)
{
	int x = A[r];
	int i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (A[j] <= x)
		{
			i += 1;
			exchange(A[i], A[j]);
		}
	}
	exchange(A[i + 1], A[r]);
	return i + 1;
}
