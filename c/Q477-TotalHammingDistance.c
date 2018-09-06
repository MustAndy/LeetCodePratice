#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hammingDistance(int x, int y) {
  int result = 0;
  for (int i = 0; i < 30; i++) {
    if ((x & 0x00000001) != (y & 0x00000001))
      result++;
    x >>= 1;
    y >>= 1;
  }
  return result;
}
int totalHammingDistance(int *nums, int numsSize) {
  int result = 0;
  for (int i = 0; i < 32; i++) {
    int temp = 0;
    for (int j = 0; j < numsSize; j++) {
      if ((nums[j] & 0x00000001) == 1)
        temp++;
      nums[j] >>= 1;
    }
    result += (temp * (numsSize - temp));
  }
  return result;
}

int main() {
  int a[5] = {4, 14, 2, 6, 8};
  int result = totalHammingDistance(a, 5);

  printf("%d\n", result);
  return 0;
}