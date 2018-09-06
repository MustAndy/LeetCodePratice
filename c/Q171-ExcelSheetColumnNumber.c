#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int titleToNumber(char *s)
{
    if (s == NULL)
    {
        return -1;
    }
    int result = 0;
    int i = 0;
    int length = strlen(s);
    for (i = 0; i < length; i++)
    {
        result += (s[i] - 64) * pow(26.0, length - 1 - i);
    }
    return result;
}
int main()
{
    char *a = (char *)malloc(1000 * sizeof(char));
    a = "AB";
    int b = titleToNumber(a);
    printf("%d\n", b);
    return 0;
}
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int titleToNumber(char* s)
{
    if (s == NULL)
    {
        return -1;
    }
    int result = 0;
    int i = 0;
    int length = strlen(s);
    for (i = 0; i < length; i++)
    {
        result += (s[i] - 64) * pow(26.0, length - 1 - i);
    }
    return result;
}
int main()
{
    char *a = (char *)malloc(1000 * sizeof(char));
