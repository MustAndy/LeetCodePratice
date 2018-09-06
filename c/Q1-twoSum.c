
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <string.h>

int *twoSum(int *nums, int numsSize, int target)
{
    int *result = (int *)malloc(2 * sizeof(int));
    int i = 0, j = 0;
    for (i = 0; i < numsSize; i++)
    {
        for (j = i + 1; j < numsSize; j++)
        {
            if (nums[j] + nums[i] == target)
            {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return result;
}

int main()
{
    int a[4] = {3, 2, 4};
    printf("%d  %d\n", a[0], a[1]);
    int *b = twoSum(a, 4, 9);
    printf("%d  %d\n", b[0], b[1]);
    return 0;
}

// #include <math.h>
// #include <stdbool.h>
// #include <stdio.h>
// #include <stdlib.h>

// #include <string.h>

// int *twoSum(int *nums, int numsSize, int target)
// {
//     int *result = (int *)malloc(2 * sizeof(int));
//     int i = 0, j = 0;
//     for (i = 0; i < numsSize; i++)
//     {
//         for (j = i + 1; j < numsSize; j++)
//         {
//             if (nums[j] + nums[i] == target)
//             {
//                 result[0] = i;
//                 result[1] = j;
//                 return result;
//             }
//         }
//     }
//     return result;
// }

// int main()
// {
//     int a[4] = {3, 2, 4};
//     printf("%d  %d\n", a[0], a[1]);
//     int *b = twoSum(a, 4, 9);
