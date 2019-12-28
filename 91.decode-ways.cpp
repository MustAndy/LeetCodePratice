/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (22.73%)
 * Likes:    1611
 * Dislikes: 1862
 * Total Accepted:    286.5K
 * Total Submissions: 1.3M
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 * 
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * Given a non-empty string containing only digits, determine the total number
 * of ways to decode it.
 * 
 * Example 1:
 * 
 * 
 * Input: "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "226"
 * Output: 3
 * Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
 * 6).
 * 
 */
#include <string>
using namespace std;
class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.size();
        if (!n || s[0] == '0')
            return 0;
        int f0 = 1, f1 = 1, f2, i;
        for (i = 2; i <= n; ++i)
        {
            f2 = (int)(s[i - 1] != '0') * f1 + (int)((s[i - 2] == '1') || (s[i - 2] == '2' && s[i - 1] < '7')) * f0;
            f0 = f1;
            f1 = f2;
        }
        return f1;
    }
    int numDecodings1(string s)
    {
        int n = s.size();
        if (!n || s[0] == '0')
            return 0;
        int dp[n + 1] = {1, 1}, i;
        for (i = 2; i <= n; ++i)
        {
            dp[i] = (int)(s[i - 1] != '0') * dp[i - 1] + (int)((s[i - 2] == '1') || (s[i - 2] == '2' && s[i - 1] < '7')) * dp[i - 2];
        }
        return dp[n];
    }
};
