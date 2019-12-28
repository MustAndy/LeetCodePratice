/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (53.18%)
 * Likes:    810
 * Dislikes: 116
 * Total Accepted:    382K
 * Total Submissions: 717.6K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t , write a function to determine if t is an anagram
 * of s.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "rat", t = "car"
 * Output: false
 * 
 * 
 * Note:
 * You may assume the string contains only lowercase alphabets.
 * 
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your
 * solution to such case?
 * 
 */
#include <string>
using namespace std;
#include <vector>

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        int n = s.length();
        int counts[26] = {0};
        for (int i = 0; i < n; i++)
        {
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
            if (counts[i])
                return false;
        return true;
    }
    bool isAnagram_sort(string s, string t)
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
    bool isAnagram_slow(string s, string t)
    {
        int lengthS = s.size(), lengthT = t.size();
        if (lengthS != lengthT)
            return false;
        int i = 0, j = 0;
        for (i = 0; i < t.size(); i++)
        {
            for (j = 0; j < s.size(); j++)
            {
                if (s[j] == t[i])
                {
                    s.erase(j, 1);
                    break;
                }
            }
        }

        if (s.size() == 0)
            return true;
        else
        {
            return false;
        }
        return false;
    }
};
