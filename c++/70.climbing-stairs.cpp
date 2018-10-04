/*
 * [70] Climbing Stairs
 *
 * https://leetcode.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (42.03%)
 * Total Accepted:    290.6K
 * Total Submissions: 691.5K
 * Testcase Example:  '2'
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 *
 * Note: Given n will be a positive integer.
 *
 * Example 1:
 *
 *
 * Input: 2
 * Output: 2
 * Explanation: There are two ways to climb to the top.
 * 1. 1 step + 1 step
 * 2. 2 steps
 *
 *
 * Example 2:
 *
 *
 * Input: 3
 * Output: 3
 * Explanation: There are three ways to climb to the top.
 * 1. 1 step + 1 step + 1 step
 * 2. 1 step + 2 steps
 * 3. 2 steps + 1 step
 *
 * Input: 4
 * Output: 5
 * Explanation: Tere are five ways to climb to the top.
 * 1. 1+1+1+1
 * 2. 1+1+2
 * 3. 1+2+1
 * 4. 2+1+1
 * 5. 2+2
 *
 * Input: 5
 * Output:
 * Explanation: Tere are five ways to climb to the top.
 * 1. 1+1+1+1+1
 * 2. 1+1+1+2
 * 3. 1+1+2+1
 * 4. 1+2+1+1
 * 5. 2+1+1+1
 * 6. 2+2+1
 * 7. 1+2+2
 * 8. 2+1+2
 *
 *
 *
 * 对于这道题，每到一节台阶，就有两种选择，迈一步or迈两步，形成一种递归的思想。
 * 但是递归的时间复杂度为n！，对于leetcode基本都会TLE，所以舍弃算法。具体算法为
 * int climbStairsRecur(int n) {
                if (n == 1) return 1;
                if (n == 2) return 2;
                return climbStairsRecur(n-1) + climbStairsRecur(n-2);
        }
 *
 * 所以我们要转换思路，使用动态规划的思想。

*/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  public:
    int climbStairs(int n)
    {
        if (n < 4)
            return n;
        int a = 2, b = 3, c = 5;
        for (int i = 5; i <= n; i++)
        {
            a = c;
            c = b + c;
            b = a;
        }
        return c;
    }
};
