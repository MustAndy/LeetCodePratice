/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */
#include <string>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int i, j;
        for (i = 0, j = s.length() - 1; i < j; ++i, --j)
        {
            while (i < j && !isalnum(s[i]))
                ++i;
            while (i < j && !isalnum(s[j]))
                --j;
            if (i < j && tolower(s[i]) != tolower(s[j]))
                return false;
        }
        return true;
    }
};
