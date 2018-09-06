#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
He uses a integer map to record the number of every char.
*/
int numJewelsInStones1(char *J, char *S)
{
    int size = 'z' - 'A' + 1;
    printf("%d", size);
    int map[size];
    int i = 0;
    for (i = 0; i < size; i++)
    {
        map[i] = -1;
    }
    i = 0;
    while (J[i] != '\0')
    {
        map[J[i] - 'A'] = 0;
        i++;
    }
    i = 0;
    int sum = 0;
    while (S[i] != '\0')
    {
        if (map[S[i] - 'A'] == 0)
            sum++;
        i++;
    }
    return sum;
}

int numJewelsInStones2(char *J, char *S)
{
    int result = 0;
    for (int i = 0; i < strlen(J); i++)
    {
        for (int j = 0; j < strlen(S); j++)
        {
            if (J[i] == S[j])
                result++;
        }
    }
    return result;
}
int main()
{
    char a[] = "aA";
    char b[] = "aAAbbbb";
    int result = numJewelsInStones(a, b);
    printf("%d", result);
    return 0;
}