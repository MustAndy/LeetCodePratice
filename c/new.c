

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool LargeThanZero(int *b, int bSize)
{
    for (int i = bSize - 1; i >= 0; i--)
    {
        if (b[i] > 0)
            return true;
    }
    return false;
}
void divv(int *b, int bSize)
{
    int tmp = 0;
    for (int i = 0; i < bSize; i++)
    {
        b[i] += tmp * 10;
        tmp = b[i] % 2;
        b[i] = b[i] / 2;
    }
}
int superPow(int a, int *b, int bSize)
{
    if (LargeThanZero(b, bSize) == false)
        return 1;
    a = a % 1377;
    bool isEven = false;
    if (b[bSize - 1] % 2 == 0)
        isEven = true;
    divv(b, bSize);
    int result = superPow(a, b, bSize);
    result = result % 1377;
    result *= result;
    result = result % 1377;
    if (isEven == false)
    {
        result *= a;
        result = result % 1377;
    }
    return result;
}
int main()
{

    int b[1001] = {
        1, 7, 7, 4, 3, 1, 7, 0, 1, 4, 4, 9, 2, 8, 5, 0, 0, 9, 3, 1, 2, 5, 9, 6, 0,
        9, 9, 0, 9, 6, 0, 5, 3, 7, 9, 8, 8, 9, 8, 2, 5, 4, 1, 9, 3, 8, 0, 5, 9, 5,
        6, 1, 1, 8, 9, 3, 7, 8, 5, 8, 5, 5, 3, 0, 4, 3, 1, 5, 4, 1, 7, 9, 6, 8, 8,
        9, 8, 0, 6, 7, 8, 3, 1, 1, 1, 0, 6, 8, 1, 1, 6, 6, 9, 1, 8, 5, 6, 9, 0, 0,
        1, 7, 1, 7, 7, 2, 8, 5, 4, 4, 5, 2, 9, 6, 5, 0, 8, 1, 0, 9, 5, 8, 7, 6, 0,
        6, 1, 8, 7, 2, 9, 8, 1, 0, 7, 9, 4, 7, 6, 9, 2, 3, 1, 3, 9, 9, 6, 8, 0, 8,
        9, 7, 7, 7, 3, 9, 5, 5, 7, 4, 9, 8, 3, 0, 1, 2, 1, 5, 0, 8, 4, 4, 3, 8, 9,
        3, 7, 5, 3, 9, 4, 4, 9, 3, 3, 2, 4, 8, 9, 3, 3, 8, 2, 8, 1, 3, 2, 2, 8, 4,
        2, 5, 0, 6, 3, 0, 9, 0, 5, 4, 1, 1, 8, 0, 4, 2, 5, 8, 2, 4, 2, 7, 5, 4, 7,
        6, 9, 0, 8, 9, 6, 1, 4, 7, 7, 9, 7, 8, 1, 4, 4, 3, 6, 4, 5, 2, 6, 0, 1, 1,
        5, 3, 8, 0, 9, 8, 8, 0, 0, 6, 1, 6, 9, 6, 5, 8, 7, 4, 8, 9, 9, 2, 4, 7, 7,
        9, 9, 5, 2, 2, 6, 9, 7, 7, 9, 8, 5, 9, 8, 5, 5, 0, 3, 5, 8, 9, 5, 7, 3, 4,
        6, 4, 6, 2, 3, 5, 2, 3, 1, 4, 5, 9, 3, 3, 6, 4, 1, 3, 3, 2, 0, 0, 4, 4, 7,
        2, 3, 3, 9, 8, 7, 8, 5, 5, 0, 8, 3, 4, 1, 4, 0, 9, 5, 5, 4, 4, 9, 7, 7, 4,
        1, 8, 7, 5, 2, 4, 9, 7, 9, 1, 7, 8, 9, 2, 4, 1, 1, 7, 6, 4, 3, 6, 5, 0, 2,
        1, 4, 3, 9, 2, 0, 0, 2, 9, 8, 4, 5, 7, 3, 5, 8, 2, 3, 9, 5, 9, 1, 8, 8, 9,
        2, 3, 7, 0, 4, 1, 1, 8, 7, 0, 2, 7, 3, 4, 6, 1, 0, 3, 8, 5, 8, 9, 8, 4, 8,
        3, 5, 1, 1, 4, 2, 5, 9, 0, 5, 3, 1, 7, 4, 8, 9, 6, 7, 2, 3, 5, 5, 3, 9, 6,
        9, 9, 5, 7, 3, 5, 2, 9, 9, 5, 5, 1, 0, 6, 3, 8, 0, 5, 5, 6, 5, 6, 4, 5, 1,
        7, 0, 6, 3, 9, 4, 4, 9, 1, 3, 4, 7, 7, 5, 8, 2, 0, 9, 2, 7, 3, 0, 9, 0, 7,
        7, 7, 4, 1, 2, 5, 1, 3, 3, 6, 4, 8, 2, 5, 9, 5, 0, 8, 2, 5, 6, 4, 8, 8, 8,
        7, 3, 1, 8, 5, 0, 5, 2, 4, 8, 5, 1, 1, 0, 7, 9, 6, 5, 1, 2, 6, 6, 4, 7, 0,
        9, 5, 6, 9, 3, 7, 8, 8, 8, 6, 5, 8, 3, 8, 5, 4, 5, 8, 5, 7, 5, 7, 3, 2, 8,
        7, 1, 7, 1, 8, 7, 3, 3, 6, 2, 9, 3, 3, 9, 3, 1, 5, 1, 5, 5, 8, 1, 2, 7, 8,
        9, 2, 5, 4, 5, 4, 2, 6, 1, 3, 6, 0, 6, 9, 6, 1, 0, 1, 4, 0, 4, 5, 5, 8, 2,
        2, 6, 3, 4, 3, 4, 3, 8, 9, 7, 5, 5, 9, 1, 8, 5, 9, 9, 1, 8, 7, 2, 1, 1, 8,
        1, 5, 6, 8, 5, 8, 0, 2, 4, 4, 7, 8, 9, 5, 9, 8, 0, 5, 0, 3, 5, 5, 2, 6, 8,
        3, 4, 1, 4, 7, 1, 7, 2, 7, 5, 8, 8, 7, 2, 2, 3, 9, 2, 2, 7, 3, 2, 9, 0, 2,
        3, 6, 9, 7, 2, 8, 0, 8, 1, 6, 5, 2, 3, 0, 2, 0, 0, 0, 9, 2, 2, 2, 3, 6, 6,
        0, 9, 1, 0, 0, 3, 5, 8, 3, 2, 0, 3, 5, 1, 4, 1, 6, 8, 7, 6, 0, 9, 8, 0, 1,
        0, 4, 5, 6, 0, 2, 8, 2, 5, 0, 2, 8, 5, 2, 3, 0, 2, 6, 7, 3, 0, 0, 2, 1, 9,
        0, 1, 9, 9, 2, 0, 1, 6, 7, 7, 9, 9, 6, 1, 4, 8, 5, 5, 6, 7, 0, 6, 1, 7, 3,
        5, 9, 3, 9, 0, 5, 9, 2, 4, 8, 6, 6, 2, 2, 3, 9, 3, 5, 7, 4, 1, 6, 9, 8, 2,
        6, 9, 0, 0, 8, 5, 7, 7, 0, 6, 0, 5, 7, 4, 9, 6, 0, 7, 8, 4, 3, 9, 8, 8, 7,
        4, 1, 5, 6, 0, 9, 4, 1, 9, 4, 9, 4, 1, 8, 6, 7, 8, 2, 5, 2, 3, 3, 4, 3, 3,
        1, 6, 4, 1, 6, 1, 5, 7, 8, 1, 9, 7, 6, 0, 8, 0, 1, 4, 4, 0, 1, 1, 8, 3, 8,
        3, 8, 3, 9, 1, 6, 0, 7, 1, 3, 3, 4, 9, 3, 5, 2, 4, 2, 0, 7, 3, 3, 8, 7, 7,
        8, 8, 0, 9, 3, 1, 2, 2, 4, 3, 3, 3, 6, 1, 6, 9, 6, 2, 0, 1, 7, 5, 6, 2, 5,
        3, 5, 0, 3, 2, 7, 2, 3, 0, 3, 6, 1, 7, 8, 7, 0, 4, 0, 6, 7, 6, 6, 3, 9, 8,
        5, 8, 3, 3, 0, 9, 6, 7, 1, 9, 2, 1, 3, 5, 1, 6, 3, 4, 3, 4, 1, 6, 8, 4, 2,
        5};
    int a = superPow(78267, b, 1000);
    printf("\n%d\n", a);
    return 0;
}
