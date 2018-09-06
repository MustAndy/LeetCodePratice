
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool checkPerfectNumber(int num) {
  if (num == 0)
    return false;
  int temp = num;
  int sum = 0;
  for (int i = 1; i < num / 2 + 1; i++) {
    if (temp % i == 0)
      sum += i;
  }
  if (sum == num)
    return true;
  else
    return false;
}
int main() {
  bool a;
  a = checkPerfectNumber(99999996);

  printf("%d\n", a);
  return 0;
}