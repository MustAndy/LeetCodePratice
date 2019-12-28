/*
 * @Author: AndyWong
 * @Date: 2018-09-19 16:55:34
 * @Last Modified by: AndyWong
 * @Last Modified time: 2018-09-19 17:00:37
 */

/*
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (25.61%)
 * Total Accepted:    373K
 * Total Submissions: 1.5M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 *
 * Example 1:
 *
 *
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 *
 *
 * Example 2:
 *
 *
 * Input: "cbbd"
 * Output: "bb"
 *
 *
 */

/*回文算法：马拉车算法：http://www.cnblogs.com/grandyang/p/4475985.html*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string longestPalindrome(string s)
    {
        const int length = s.length();
        if (s.length() == 1)
            return s;

        int max_s = 0, max_l = 0;
        for (int i = 0; i < length;)
        {
        }
    }
    string longestPalindrome1(string s)
    {

        int length = s.length();
        if (s.length() == 1)
            return s;
        string result;
        string manacher;
        manacher += "$#";
        for (int i = 0; i < length; ++i)
        {

            manacher += s[i];
            manacher += '#';
        }
        int p[manacher.size()] = {0}, id = 0; //回文子串的中心点

        int mx = 0; //回文串能延伸到的最右端的位置
        int resLen = 0, resMx = 0;

        for (int i = 1; i < manacher.size(); ++i)
        {
            p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
            while (manacher[i + p[i]] == manacher[i - p[i]])
                ++p[i];
            if (mx < i + p[i])
            {
                mx = i + p[i];
                id = i;
            }
            if (resLen < p[i])
            {
                resLen = p[i];
                resMx = i;
            }
        }
        return s.substr((resMx - resLen) / 2, resLen - 1);
        ;
    }
};