#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *toLowerCase(char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if ((str[i] > 64) && (str[i] < 91))
            str[i] += 32;
    }
    return str;
}
int main()
{
    char a[] = "NYVGTHJBKJUIHYGTFRHVGJHBKJA";
    char *b;

    b = toLowerCase(a);
    printf("%s", b);
    return 0;
}
