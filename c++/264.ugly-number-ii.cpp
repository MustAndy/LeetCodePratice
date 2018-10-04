/*
 * [264] Ugly Number II
 *
 * https://leetcode.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (34.22%)
 * Total Accepted:    85K
 * Total Submissions: 248.4K
 * Testcase Example:  '10'
 *
 * Write a program to find the n-th ugly number.
 *
 * Ugly numbers are positive numbers whose prime factors only include 2, 3,
 * 5. 
 *
 * Example:
 *
 *
 * Input: n = 10
 * Output: 12
 * Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10
 * ugly numbers.
 *
 * Note:  
 *
 *
 * 1 is typically treated as an ugly number.
 * n does not exceed 1690.
 *
 * 原始方法是调用isUgly方法去一个一个数的判断，非常低效，而且会有TLE。
 * 因此改变思路，通过2,3,5，三个数分别去生成下一个ugly数。
 *
 */
#include <iostream>
#include <vector>

using namespace std;
class Solution
{
  public:
    bool isUgly(int num)
    {
        if (num <= 0)
            return false;
        if (num == 1)
            return true;
        while (num >= 2 && num % 2 == 0)
            num /= 2;
        while (num >= 3 && num % 3 == 0)
            num /= 3;
        while (num >= 5 && num % 5 == 0)
            num /= 5;

        return num == 1;
    }

    int nthUglyNumber1(int n)
    {
        int result = 0, i = 0, count = 0;
        bool judge;

        while (count < n)
        {
            judge = isUgly(i);
            if (judge == true)
            {
                result = i;
                count++;
            }
            i++;
        }
        return result;
    }
    int nthUglyNumber(int n)
    {
        vector<int> res{1};
        int ith2 = 0, ith3 = 0, ith5 = 0;
        while (--n > 0)
        {
            int val = min(res[ith2] * 2, min(res[ith3] * 3, res[ith5] * 5));
            res.push_back(val);
            while (res[ith2] * 2 <= val)
                ith2++;
            while (res[ith3] * 3 <= val)
                ith3++;
            while (res[ith5] * 5 <= val)
                ith5++;
        }
        return res.back();
    }
};
