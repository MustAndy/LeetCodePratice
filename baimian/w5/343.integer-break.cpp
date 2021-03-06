/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 *
 * https://leetcode.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (48.35%)
 * Likes:    661
 * Dislikes: 184
 * Total Accepted:    86.9K
 * Total Submissions: 179.2K
 * Testcase Example:  '2'
 *
 * Given a positive integer n, break it into the sum of at least two positive
 * integers and maximize the product of those integers. Return the maximum
 * product you can get.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: 2
 * Output: 1
 * Explanation: 2 = 1 + 1, 1 × 1 = 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 10
 * Output: 36
 * Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 * 
 * Note: You may assume that n is not less than 2 and not larger than 58.
 * 
 * 
 */
class Solution
{
public:
    int integerBreak(int n)
    {
        vector<int> dp{0, 0, 1, 2, 4, 6, 9};
        for (int i = 7; i <= n; ++i)
        {
            dp.push_back(3 * dp[i - 3]);
        }
        return dp[n];
    }
};
