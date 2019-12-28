/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 *
 * https://leetcode.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (48.52%)
 * Likes:    590
 * Dislikes: 64
 * Total Accepted:    106.3K
 * Total Submissions: 218.9K
 * Testcase Example:  '"abccccdd"'
 *
 * Given a string which consists of lowercase or uppercase letters, find the
 * length of the longest palindromes that can be built with those letters.
 * 
 * This is case sensitive, for example "Aa" is not considered a palindrome
 * here.
 * 
 * Note:
 * Assume the length of given string will not exceed 1,010.
 * 
 * 
 * Example: 
 * 
 * Input:
 * "abccccdd"
 * 
 * Output:
 * 7
 * 
 * Explanation:
 * One longest palindrome that can be built is "dccaccd", whose length is 7.
 * 
 * 
 */
#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int longestPalindrome(string s)
    {
        int odd = 0;
        unordered_map<char, int> m;
        for (auto c : s)
            odd += m[c]++ % 2 ? -1 : 1;
        return min(s.size(), s.size() - odd + 1);
    }

    int longestPalindrome1(string s)
    {
        int alpha[58] = {0};
        int result = 0;
        int length = s.size();
        for (int i = 0; i < length; ++i)
        {
            alpha[s[i] - 'A']++;
        }
        for (int i = 0; i < 58; ++i)
        {
            if (alpha[i] > 0 && alpha[i] % 2 == 0)
                result += alpha[i];
        }
        int max = 0;
        bool addone = false;
        for (int i = 0; i < 58; ++i)
        {
            if (alpha[i] % 2 == 1)
            {
                result += (alpha[i] - 1);
                addone = true;
            }
        }

        return addone ? (result + 1) : result;
    }
};
