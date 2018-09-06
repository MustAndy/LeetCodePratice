#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rotate(int *nums, int numsSize, int k) {
  int *temp = (int *)malloc(numsSize * sizeof(int));
  k = k % numsSize;
  for (int i = 0; i < numsSize; i++) {
    temp[k] = nums[i];
    k++;
    if (k >= numsSize)
      k -= numsSize;
  }
  for (int i = 0; i < numsSize; i++) {
    *nums = *temp;
    nums++;
    temp++;
  }
}
int main() {
  int a[7] = {1, 2, 3, 4, 5, 6, 7};
  rotate(a, 7, 3);
  for (int i = 0; i < 7; i++)
    printf("%d ", a[i]);
  printf("\n");
  return 0;
}
// #include <math.h>
// #include <stdbool.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// void rotate(int* nums, int numsSize, int k)
// {
//     int *temp = (int *)malloc(numsSize * sizeof(int));
//     k = k % numsSize;
//     for (int i = 0; i < numsSize; i++)
//     {
//         temp[k] = nums[i];
//         k++;
//         if (k >= numsSize)
//             k -= numsSize;
//     }
//     for (int i = 0; i < numsSize; i++)
//     {
//         *nums = *temp;
//         nums++;
//         temp++;
//     }
// }
// int main()
// {
//     int a[7] = {1, 2, 3, 4, 5, 6, 7};
