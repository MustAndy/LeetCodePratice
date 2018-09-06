
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
int compareVersion(char *version1, char *version2)
{
    char *v1Save;
    char *v2Save;
    char *v1Piece = strtok_r(version1, ".", &v1Save);
    char *v2Piece = strtok_r(version2, ".", &v2Save);
    if (v1Piece == NULL)
        v1Piece = version1; // versions with no dot
    if (v2Piece == NULL)
        v2Piece = version2; // versions with no dot
    while (1)
    {
        if (v1Piece == NULL && v2Piece == NULL)
        {
            return 0;
        }
        else if (v1Piece == NULL && v2Piece != NULL)
        {
            if (atoi(v2Piece) != 0)
            {
                return -1;
            }
            else
            {
                v1Piece = v2Piece;
            }
        }
        else if (v1Piece != NULL && v2Piece == NULL)
        {
            if (atoi(v1Piece) != 0)
            {
                return 1;
            }
            else
            {
                v2Piece = v1Piece;
            }
        }

        if (atoi(v1Piece) > atoi(v2Piece))
        {
            return 1;
        }
        else if (atoi(v1Piece) < atoi(v2Piece))
        {
            return -1;
        }
        else
        {
            v1Piece = strtok_r(NULL, ".", &v1Save);
            v2Piece = strtok_r(NULL, ".", &v2Save);
        }
    }
    return 0;
}

int main()
{

    int b = compareVersion("1.1", "0.1");
    printf("%d\n", b);
    return 0;
}