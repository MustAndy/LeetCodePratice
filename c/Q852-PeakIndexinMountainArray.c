#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int peakIndexInMountainArray(int *A, int ASize)
{
    for (int i = 0; i < ASize; i++)
    {
        if (A[i] > A[i + 1])
            return i;
    }
    return 0;
}
int main()
{
    int a[] = {0, 2, 1, 0};
    int result = peakIndexInMountainArray(a, 4);
    printf("%d", result);
    return 0;
}
