#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint32_t reverseBits(uint32_t n) {
  uint32_t result = 0;
  int i = 31;
  while (1) {
    printf("%u", (n & 0x00000001));
    result = result | ((n & 0x00000001) << i);
    n >>= 1;
    if (n == 0)
      break;
    i--;
    // result <<= 1;
  }
  printf("\n%u\n", result);
  return result;
}
int main() {
  uint32_t a;
  uint32_t b = 43261596;
  a = reverseBits(b);
  return 0;
}
// #include <math.h>
// #include <stdbool.h>
// #include <stdint.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// uint32_t reverseBits(uint32_t n)
// {
//     uint32_t result = 0;
//     int i = 31;
//     while (1)
//     {
//         printf("%u", (n & 0x00000001));
//         result = result | ((n & 0x00000001) << i);
//         n >>= 1;
//         if (n == 0)
//             break;
//         i--;
//         result <<= 1;
//     }
