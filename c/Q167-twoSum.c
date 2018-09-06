
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int *twoSum(int *numbers, int numbersSize, int target, int *returnSize)
{
    int i = 0, j = numbersSize - 1;
    int *returnArray = NULL;
    while (i < numbersSize && j >= 0)
    {
        if (numbers[i] + numbers[j] > target)
            j--;
        else if (numbers[i] + numbers[j] < target)
            i++;
        else
        {
            *returnSize = 2;
            returnArray = malloc((*returnSize) * sizeof(int));
            returnArray[0] = i + 1;
            returnArray[1] = j + 1;
            return returnArray;
        }
    }
    return returnArray;
}

int main()
{
    int test[4] = {2, 7, 13, 15};
    int returnSize;
    int returnArray[4];
    twoSum(test, 4, 9, returnSize);
    return 0;
}