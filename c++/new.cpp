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
#include <vector>
using namespace std;

class Solution
{
  public:
    int singleNumber(vector<int> &nums)
    {
        int a = 0, b = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            b = (b ^ nums[i]) & ~a;
            a = (a ^ nums[i]) & ~b;
        }
        return b;
    }
};
int main()
{
    Solution temp1;
    vector<int> temp;
    temp.push_back(2);
    temp.push_back(4);
    temp.push_back(2);
    temp.push_back(4);
    temp.push_back(3);
    temp.push_back(2);
    temp.push_back(4);
    int result = temp1.singleNumber(temp);
    cout << (3 ^ 5) << (7 & 6) << (7 | 6);
    return 0;
}