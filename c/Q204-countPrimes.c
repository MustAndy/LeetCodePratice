#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
int countPrimes(int n)
{
    bool *flag = (bool *)calloc(n + 1, sizeof(bool));
    int *prime = (int *)calloc(n / 2, sizeof(int));

    flag[0] = 1; /* dummy */
    flag[1] = 1; /* dummy, 1 is not prime */

    int i, j;
    int count = 0;
    for (i = 2; i < n; i++)
    {
        if (flag[i] == 0)
        { /* i is prime */
            prime[count++] = i;
        }
        for (j = 0; j < count && i * prime[j] < n; j++)
        {
            flag[i * prime[j]] = 1;
            if (i % prime[j] == 0)
            { /* important */
                break;
            }
        }
    }
    return count;
}

int main(void)
{
    int a;

    a = countPrimes(500000);
    printf("%d\n", a);

    return 0;
}
