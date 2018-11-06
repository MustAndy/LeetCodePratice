/*
 * @Author: AndyWong
 * @Date: 2018-09-10 15:39:28
 * @Last Modified by: AndyWong
 * @Last Modified time: 2018-09-19 17:25:28
 */
#include <algorithm>
#include <iostream>
#include <limits.h>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
  public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> m;
        for (char c : s)
            ++m[c];
        for (int i = 0; i < s.size(); ++i)
        {
            if (m[s[i]] == 1)
                return i;
        }
        return -1;
    }
};

int main()
{
    Solution temp1;

    int result = temp1.firstUniqChar("aabbab");
    cout << result;
    return 0;
}