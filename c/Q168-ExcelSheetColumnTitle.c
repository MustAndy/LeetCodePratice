#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *convertToTitle(int n)
{
    if (n <= 0)
    {
        return "";
    }
    char *result = (char *)malloc(1000 * sizeof(char));
    int len = 0;
    do
    {
        result[len++] = ((n - 1) % 26) + 'A';
        n = (n - 1) / 26;
    } while (n > 0);
    result[len] = '\0';

    int i, j;
    for (i = 0, j = len - 1; i < j; i++, j--)
    {
        char c = result[i];
        result[i] = result[j];
        result[j] = c;
    }
    return result;
}
int main()
{
    char *a = (char *)malloc(1000 * sizeof(char));
    a = convertToTitle(26);
    printf("%s\n", a);
    return 0;
}
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convertToTitle(int n)
{
    if (n <= 0)
    {
        return "";
    }
    char *result = (char *)malloc(1000 * sizeof(char));
    int len = 0;
    do
    {
        result[len++] = ((n - 1) % 26) + 'A';
        n = (n - 1) / 26;
    } while (n > 0);
    result[len] = '\0';

    int i, j;
    for (i = 0, j = len - 1; i < j; i++, j--)
    {
        char c = result[i];
        result[i] = result[j];
        result[j] = c;
    }
    return result;
}
int main()
{
    char *a = (char *)malloc(1000 * sizeof(char));
