#include <time.h>
#include "func.h"

static void exchange(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


static int randomSelectPos(int *A, int p, int r, int i)
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

extern int findMedian(int *A, int p, int q) {
    int medians[5], setSize, startPos = 0;
    if (q - p + 1 < 5) 
        return randomSelectPos(A, p, q, (q - p + 1) / 2);
    else if ((q - p + 1) % 5 != 0)
        setSize = (q - p + 1) / 4;
    else
        setSize = (q - p + 1) / 5;
    for (int i = 0; i < 4; i++) {
        medians[i] = randomSelectPos(A, startPos, startPos + setSize - 1, setSize / 2);
        startPos += setSize;
    }
    medians[4] = randomSelectPos(A, startPos, q, (q - startPos) / 2);
    return randomSelectPos(medians, 0, 4, 3);
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