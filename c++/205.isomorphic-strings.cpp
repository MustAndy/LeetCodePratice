/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 *
 * https://leetcode.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (36.32%)
 * Total Accepted:    178.6K
 * Total Submissions: 491.6K
 * Testcase Example:  '"egg"\n"add"'
 *
 * Given two strings s and t, determine if they are isomorphic.
 * 
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * 
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character but a character may map to itself.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "egg", t = "add"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "foo", t = "bar"
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: s = "paper", t = "title"
 * Output: true
 * 
 * Note:
 * You may assume both s and t have the same length.
 * 
 */
#include <iostream>
#include <string>
using namespace std;
class Solution
{
  public:
    bool isIsomorphic(string s, string t)
    {
        int a[256] = {0}, b[256] = {0};
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (a[s[i]] != b[t[i]])
                return false;
            a[s[i]] = i + 1;
            b[t[i]] = i + 1;
        }
        return true;
    }
};
