
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findPeakElement(int *nums, int numsSize)
{
    if (numsSize == 1)
        return 0;
    if (numsSize == 2)
        return (nums[0] > nums[1]) ? 0 : 1;
    if (numsSize >= 3)
        for (int i = 1; i < numsSize; i++)
        {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
                return i;
        }

    return (nums[0] > nums[numsSize - 1]) ? 0 : (numsSize - 1);
}
int main()
{
    int a[] = {2, 1};
    int result = findPeakElement(a, 2);
    printf("%d", result);
    return 0;
}