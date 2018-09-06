#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hammingWeight(uint32_t n)
{
    int i = 0;
    int counter;
    for (i = 0; i < 32; i++)
    {
        if ((n & 0x00000001) == 1)
        {
            counter++;
        }
        n >>= 1;
    }
    return counter;
}
int main()
{
    int a;
    uint32_t b = 11;
    a = hammingWeight(b);
    printf("%d", a);
    return 0;
}