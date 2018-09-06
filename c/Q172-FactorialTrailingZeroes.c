#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int trailingZeroes(int n)
{
    long int FiveCounter = 0, FiveTemp;
    long int i = 0;
    // FiveCounter = n / 5 + n / 25 + n / 125 + n / 625;
    while (n > 0)
    {
        FiveCounter += n / 5;
        n /= 5;
    }
    return FiveCounter;
}
int main()
{
    int n = 25;
    for (int i = 5; i < 1000; i += 5)
    {
        int b = trailingZeroes(i);
        printf("%d %d\n", i, b);
    }
    return 0;
}
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int trailingZeroes(int n)
{
    long int FiveCounter = 0, FiveTemp;
    long int i = 0;
    // FiveCounter = n / 5 + n / 25 + n / 125 + n / 625;
    while (n > 0)
    {
        FiveCounter += n / 5;
        n /= 5;
    }
    return FiveCounter;
}
int main()
{
    int n = 25;
    for (int i = 5; i < 1000; i += 5)
    {
        int b = trailingZeroes(i);
        printf("%d %d\n", i, b);
    }
