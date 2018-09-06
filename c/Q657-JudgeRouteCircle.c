#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
bool judgeCircle(char *moves)
{
    int x = 0, y = 0;
    int len = strlen(moves);
    for (int i = 0; i < len; i++)
    {
        switch (moves[i])
        {
        case 'U':
            y++;
            break;
        case 'D':
            y--;
            break;
        case 'L':
            x++;
            break;
        case 'R':
            x--;
            break;
        }
    }
    if (x == 0 && y == 0)
        return true;
    else
        return false;
}

int main()
{
    char a[] = "UD";
    bool b = judgeCircle(a);
    printf("%d", b);
    return 0;
}
