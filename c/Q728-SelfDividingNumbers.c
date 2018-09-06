
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkNum(int num) {
  int temp = num;

  while (temp != 0) {
    if ((temp % 10) == 0)
      return 0;
    if ((num % (temp % 10) == 0))
      temp /= 10;
    else
      return 0;
  }

  return 1;
}

int *selfDividingNumbers(int left, int right, int *returnSize) {
  int *b = malloc(sizeof(int) * (right - left + 1));
  *returnSize = 5;
  int booleanNum;
  *returnSize = 0;
  while (left <= right) {
    if (left % 10 == 0) {
      left++;
      continue;
    }
    booleanNum = checkNum(left);
    if (booleanNum == 1) {
      b[(*returnSize)] = left;

      (*returnSize)++;
    }
    left++;
  }
  return b;
}
int main() {
  int returnsize = 1;

  int *b = selfDividingNumbers(1, 22, &returnsize);
  // int b = checkNum(21);
  for (int i = 0; i < returnsize; i++)
    printf("%d\n", b[i]);
  return 0;
}