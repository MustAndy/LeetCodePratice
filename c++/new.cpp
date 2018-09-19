/*
 * @Author: AndyWong
 * @Date: 2018-09-10 15:39:28
 * @Last Modified by: AndyWong
 * @Last Modified time: 2018-09-10 17:28:27
 */
#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;
class Solution
{
  public:
    int mySqrt(int x)
    {
        long long int mult;
        if (x > 2147395600)
            return 46340;
        for (int i = 0; i <= x; i++)
        {
            mult = i * i;
            if (mult == x)
                return i;
            else if (mult > x)
                return i - 1;
        }
        return 0;
    }
};

int main()
{
    Solution temp;
    int a = 2147483646;

    int result = temp.mySqrt(a);
    cout << result;
    return 0;
}