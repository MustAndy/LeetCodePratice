#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *toHex(int num)
{
    char hexChar[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                        '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    char *result = (char *)malloc(100 * sizeof(char));
    unsigned int mask = 0xF << 28;

    unsigned int num_ = num;

    if (num == 0)
        return "0";
    int j = 0;
    if (num < 0)
    {
        num_ = abs(num);
        num_ = ~num_ + 1;
    }
    for (int i = 7; i >= 0; i--)
    {
        unsigned int n = num_ & mask;
        // printf("%d\n", n);
        while (n >= 16)
        {
            n = n >> 4;
        }
        // if ((result == NULL && n > 0) || (strlen(result) > 0)) {
        if (n > 0 || (strlen(result) > 0))
        {
            result[j] = hexChar[n];
            j++;
        }
        mask = mask >> 4;
    }

    return result;
}

int main()
{
    char *a = (char *)malloc(100 * sizeof(char));
    a = toHex(16);
    printf("%s\n", a);
    return 0;
}