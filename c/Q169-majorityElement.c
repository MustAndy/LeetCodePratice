#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Given an array of size n, find the majority element. The majority element is
// the element that appears more than ⌊ n/2 ⌋ times.

// You may assume that the array is non-empty and the majority element always
// exist in the array.

typedef struct _Node
{
    int value;
    int index;
    int count;
} Node, *NODE;

int majorityElement(int *nums, int numsSize)
{
    if (numsSize == 1)
        return nums[0];
    int max = 0;
    int index = 0;
    NODE *a;
    a = (NODE *)malloc(numsSize * sizeof(struct _Node));
    for (int i = 0; i < numsSize; i++)
    {
        a[i] = (NODE)malloc(sizeof(struct _Node));
        a[i]->index = -1;
    }
    int nodeCount = 1;
    bool found = 0;
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = 0; j < nodeCount; j++)
        {
            if (a[j]->value == nums[i] && a[j]->index != -1)
            {
                a[j]->count++;
                found = 1;
                break;
            }
        }
        if (!found)
        {
            a[nodeCount - 1]->value = nums[i];
            a[nodeCount - 1]->count = 1;
            a[nodeCount - 1]->index = i;

            nodeCount += 1;
        }
        found = 0;
    }

    for (int i = 0; i < nodeCount; i++)
    {
        if (a[i]->count > max)
        {
            max = a[i]->count;
            index = a[i]->index;
        }
    }
    return nums[index];
}
int majorityElement1(int *nums, int numsSize)
{
    int i, count = 1, maj = 0;
    for (i = 1; i < numsSize; i++)
    {
        if (nums[maj] == nums[i])
            count++;
        else
            count--;
        if (count == 0)
        {
            maj = i;
            count = 1;
        }
    }
    return nums[maj];
}
int main()
{
    int a[100] = {72, 47, 47, 47, 72, 47, 79, 47, 12, 92, 13, 47, 47, 83, 33,
                  15, 18, 47, 47, 47, 47, 64, 47, 65, 47, 47, 47, 47, 70, 47,
                  47, 55, 47, 15, 60, 47, 47, 47, 47, 47, 46, 30, 58, 59, 47,
                  47, 47, 47, 47, 90, 64, 37, 20, 47, 100, 84, 47, 47, 47, 47,
                  47, 89, 47, 36, 47, 60, 47, 18, 47, 34, 47, 47, 47, 47, 47,
                  22, 47, 54, 30, 11, 47, 47, 86, 47, 55, 40, 49, 34, 19, 67,
                  16, 47, 36, 47, 41, 19, 80, 47, 47, 27};
    int b = majorityElement(a, 100);

    int c[5] = {3, 3, 2, 1, 4};
    b = majorityElement1(c, 5);
    printf("%d", b);
    return 0;
}
