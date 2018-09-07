

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int x = 0;
  int result;

  result |= (x & 0x0000000f);
  result <<= 4;
  result |= (x & 0x0000000f);
  x >>= 4;
  printf("\n%d\n", x);
  return 0;
}
