#include <time.h>
#include "partition.h"

static void exchange(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

extern int randomPos(int p, int r)
{
	srand((int)time(0));
	return rand() % (r - p + 1) + p;
}

extern int randomSelect(int *A, int p, int r, int i)
{
    if (p == r)
        return A[p];
    int q = partition(A, p, randomPos(p, r), r);
    int k = q - p + 1;
    if (i == k)
        return A[q];
    else if (i < k)
        return randomSelect(A, p, q - 1, i);
    else
        return randomSelect(A, q + 1, r, i - k);
}

extern int randomSelectPos(int *A, int p, int r, int i)
{
	if (i == 0)
		i++;
    if (p == r)
        return p;
    int q = partition(A, p, randomPos(p, r), r);
    int k = q - p + 1;
    if (i == k)
        return q;
    else if (i < k)
        return randomSelectPos(A, p, q - 1, i);
    else
        return randomSelectPos(A, q + 1, r, i - k);
}

extern int partition(int *A, int p, int q, int r)
{
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