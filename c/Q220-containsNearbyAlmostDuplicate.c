
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
bool containsNearbyAlmostDuplicate(int *nums, int numsSize, int k, int t)
{
    if (numsSize == 1)
        return false;
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            long long int temp = llabs((long long)nums[i] - (long long)nums[j]);
            //printf("nums[i]:%d,nums[j]:%d,temp:%lld\n", nums[i], nums[j], temp);

            if (temp <= t && temp >= (-t))
                if ((j - i) <= k)
                    return true;
        }
    }
    return false;
}

int main()
{
    int a[4] = {-2147483647, 2147483647};
    long long int b = 2147483647 + 2147483647;
    printf("%lld\n", b);
    printf("%d\n", containsNearbyAlmostDuplicate(a, 2, 1, 2147483647));
    return 0;
}