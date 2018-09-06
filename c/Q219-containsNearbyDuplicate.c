
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
bool containsNearbyDuplicate(int *nums, int numsSize, int k)
{
    if (numsSize == 1)
        return false;
    for (int i = 0; i < numsSize; i++)
        for (int j = i + 1; j < numsSize; j++)
            if (nums[i] == nums[j])
                if ((j - i) <= k)
                    return true;
    return false;
}
int main()
{
    int a[4] = {1, 2, 3, 1};
    printf("%d\n", containsNearbyDuplicate(a, 4, 3));
    return 0;
}
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
bool containsNearbyDuplicate(int *nums, int numsSize, int k)
{
    if (numsSize == 1)
        return false;
    for (int i = 0; i < numsSize; i++)
        for (int j = i + 1; j < numsSize; j++)
            if (nums[i] == nums[j])
                if ((j - i) <= k)
                    return true;
    return false;
}
int main()
{
    int a[4] = {1, 2, 3, 1};
