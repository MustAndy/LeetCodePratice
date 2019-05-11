
/*
Time:2016-9-8 15:48:57
Author:CodingMengmeng
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
void f(int a[], int i, int j)

{

    int t;

        if (i < j)
    {
        t = a[i];
        a[i] = a[j];
        a[j] = t;
        f(a, i + 1, j - 1);
    }
}

int main()

{

    int i, a[5] = {1, 2, 3, 4, 5} ;

               f(a, 0, 4) ;

           for (i = 0; i < 5; i++) printf("%d, ", a[i]) ;
           return 0;
}