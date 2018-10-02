#include "partition.h"

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