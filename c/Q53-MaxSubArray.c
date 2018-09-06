#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int maxSubArray2(int *nums, int numsSize) {
  int temp = 0;
  int result = nums[0];
  int i, j;

  for (i = 0; i < numsSize; i++) {
    temp = 0;
    for (j = i; j < numsSize; j++) {
      temp += nums[j];
      if (temp > result) {
        result = temp;
      }
    }
  }

  return result;
}
int maxSubArray1(int *nums, int numsSize) {
  int currentSum, maxGlobalSum, index;

  if (numsSize == 1)
    return nums[0];
  else
    maxGlobalSum = currentSum = nums[0];

  for (index = 1; index < numsSize; index++) {
    currentSum += nums[index];

    if (nums[index] > currentSum)
      currentSum = nums[index];

    if (currentSum > maxGlobalSum)
      maxGlobalSum = currentSum;
  }

  return maxGlobalSum;
}
int main() {
  int a;
  int b[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  a = maxSubArray(b, 9);
  printf("%d\n", a);
  return 0;
}